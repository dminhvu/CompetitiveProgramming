/*
Task: 
Date: 
Author: aLittleLove (Minh Vu)
*/

#include<bits/stdc++.h>
#define rep(i,n) for (int i=0, _n=n; i<_n; i++)
#define FOR(i,a,b) for (int _a=(a), _b=(b), i=_a; _a<=_b?i<=_b:i>=_b; _a<=_b?i++:i--)
#define _mem(a, b) memset(a, (b), sizeof(a))
#define pb push_back
#define fi first
#define se second
#define sz(a) int((a).size())

using namespace std;
typedef long long ll;
typedef int64_t i64;
typedef pair<int, int> pii;
typedef vector<pii> vii;
typedef vector<int> vi;
const int N = 2e5 + 5;
const int inf = 1e9;
const int mod = 1e9 + 7;
const double pi = atan(1) * 4.0;
template<typename T, typename U> inline void mini(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> inline void maxi(T &x, U y) { if(x < y) x = y; }

struct myData
{
    i64 weight; int v;
    bool operator < (const myData &oth) const
    {
        return oth.weight>weight;
    }
};

int pa[N];
priority_queue<myData> leaf;
i64 a[N], ans[N];
vector<int> adj[N];
int n;
bool vis[N];

void dfs(int u)
{
    vis[u] = 1;
    //cout << u << " ";
    bool f = 1;
    for (int i=0; i<adj[u].size(); i++)
    {
        int v = adj[u][i];
        if (vis[v]) continue;
        f = 0;
        pa[v] = u;
        dfs(v);
    }
    if (f) leaf.push({a[u] + a[pa[u]], u});
}

void Solve()
{
    cin >> n;
    FOR(i,1,n) cin >> a[i], pa[i] = -1, vis[i] = 0, adj[i].clear();
    FOR(i,1,n-1)
    {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vis[1] = 1;
    dfs(1);
    i64 sum = accumulate(a+1,a+n+1,0ll);
    ans[1] = sum;
    int cnt = 1;
    while (leaf.size())
    {
        myData cur = leaf.top(); leaf.pop();
        int v = cur.v;
        int u = pa[v];
        sum += a[u];
        if (u!=1) leaf.push({a[u] + a[pa[u]], u});
        ans[++cnt] = sum;
    }
    FOR(i,1,n-1) cout << ans[i] << " ";
    cout << '\n';
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("input.txt","r",stdin);
    int nTest; cin >> nTest;
    while (nTest--) Solve();

    return 0;
}