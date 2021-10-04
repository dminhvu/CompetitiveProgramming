#include<bits/stdc++.h>

using namespace std;
const int N = 3e5 + 5;
struct Universe
{
    int p1, u2, p2;
};

struct Dijk
{
    int u, p, len;
    bool operator < (const Dijk &oth) const 
    {
        return len>oth.len;
    }
};

struct Save
{
    int p1, u1, p2, u2;
};

int n, m, q;
map<pair<int, int>, int> dist;
vector<int> g[N];
vector<Universe> h[N];
Save save[N];

int Dijkstra(int p1, int u1, int p2, int u2)
{
    priority_queue<Dijk> pq;
    pq.push({u1, p1, 0});
    dist.clear();
    dist[{u1, p1}] = 0;
    while (pq.size())
    {
        auto x = pq.top(); pq.pop();
        if (x.len!=dist[{x.u, x.p}]) continue;
        for (auto nxt: g[x.p])
        {
            if (dist[{x.u, nxt}]==0 || dist[{x.u, nxt}] > dist[{x.u, x.p}] + 1)
            {
                dist[{x.u, nxt}] = dist[{x.u, x.p}] + 1;
                pq.push({x.u, nxt, dist[{x.u, nxt}]});
                if (x.u==u2 && nxt==p2) return dist[{x.u, nxt}];
            }
        }
        for (auto nxt: h[x.u])
        {
            if (nxt.p1!=x.p) continue;
            if (dist[{nxt.u2, nxt.p2}]==0 || dist[{nxt.u2, nxt.p2}] > dist[{x.u, x.p}] + 1)
            {
                dist[{nxt.u2, nxt.p2}] = dist[{x.u, x.p}] + 1;
                pq.push({nxt.u2, nxt.p2, dist[{nxt.u2, nxt.p2}]});
                if (nxt.p2==p2 && nxt.u2==u2) return dist[{nxt.u2, nxt.p2}];
            }
        }
    }
    return -1;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("input.txt","r",stdin);
    cin >> n >> m >> q;
    int mx = 0;
    for (int i=0; i<n-1; i++)
    {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (int i=0; i<m; i++)
    {
        int u1, p1, u2, p2;
        cin >> p1 >> u1 >> p2 >> u2;
        h[u1].push_back({p1, u2, p2});
        h[u2].push_back({p2, u1, p1});
        mx = max(mx, u1);
        mx = max(mx, u2);
    }
    for (int i=0; i<q; i++)
    {
        int u1, p1, u2, p2;
        cin >> p1 >> u1 >> p2 >> u2;
        if (u1>mx || u2>mx)
        {
            if (u1==u2)
            {
                int ans = Dijkstra(p1, u1, p2, u2);
                if (ans==-1) cout << "impossible\n";
                else cout << ans << '\n';
            }
            else cout << "impossible\n";
            continue;
        }
        int ans = Dijkstra(p1, u1, p2, u2);
        if (ans==-1) cout << "impossible\n";
        else cout << ans << '\n';
    }
    return 0;
}