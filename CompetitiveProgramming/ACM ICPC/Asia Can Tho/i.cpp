#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < int(n); i++)
#define fore(i,a,b) for (int i = int(a); i <= int(b); i++)
#define ford(i,a,b) for (int i = int(a); i >= int(b); i--)
#define ll int64_t
#define pb push_back
#define fi first
#define se second
#define sz(x) int(x.size())

using namespace std;
template<class t, class u> bool maxi(t &a, u b){ if (a < b){ a = b; return 1;} return 0;}
template<class t, class u> bool mini(t &a, u b){ if (a > b){ a = b; return 1;} return 0;}
const ll inf = 1e18;

struct myData {
    int u; ll w;
    bool operator < (const myData &oth) const {
        return w > oth.w;
    }
};

vector<vector<myData> > adj;
int n, m;

class Dijkstra {
private:
    int st, ed;
public:
    vector<ll> dp1, dp2;
    Dijkstra(int x, int y) {
        dp1.resize(n, inf);
        dp2.resize(n, inf);
        st = x;
        ed = y;
    };
    void findPath(vector<ll> &dp, int now) {
        priority_queue<myData> pq;
        pq.push({now, 0});
        dp[now] = 0;
        while (pq.size()) {
            int u = pq.top().u;
            ll cur = pq.top().w;
            pq.pop();
            if (cur != dp[u]) continue;
            for(myData tmp: adj[u]) {
                int v = tmp.u;
                ll w = tmp.w;
                if (mini(dp[v], dp[u] + w)) {
                    pq.push({v, dp[v]});
                }
            }
        }
    }
    void Solve() {
        findPath(dp1, st);
        findPath(dp2, ed);
    }
    int getSt() {
        return st;
    }
    int getEd() {
        return ed;
    }
};

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("input.txt","r",stdin);
    int nTest = 0;
    while (cin >> n >> m && n != 0) {
        // cout << "Test " << (++nTest) << ":" << '\n';
        adj.resize(n);
        rep(i,n) adj[i].clear();
        int x, y;
        cin >> x >> y;
        --x; --y;
        Dijkstra a(x, y);
        cin >> x >> y;
        --x; --y;
        Dijkstra b(x, y);
        rep(i,m) {
            int u, v; cin >> u >> v;
            ll w; cin >> w;
            --u; --v;
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        a.Solve();
        b.Solve();
        ll ans = 0;
        rep(i,n) {
            if (a.dp1[i] + a.dp2[i] == a.dp1[a.getEd()] && b.dp1[i] + b.dp2[i] == b.dp1[b.getEd()]) {
                ans++;
                for (myData tmp: adj[i]) {
                    int j = tmp.u;
                    if (a.dp1[j] + a.dp2[j] == a.dp1[a.getEd()] && b.dp1[j] + b.dp2[j] == b.dp1[b.getEd()]) {
                        if (a.dp1[j] >= a.dp1[i] || b.dp1[j] >= b.dp1[i]) {
                            ans += 2;
                        }
                    }
                }
            }
            if (ans > ll(1e9)) {
                ans = -1;
                break;
            }
        }
        cout << ans;
        cout << '\n';
    }
    return 0;
}