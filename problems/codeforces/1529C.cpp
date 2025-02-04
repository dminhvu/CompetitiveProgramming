#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < int(n); i++)
#define fore(i,a,b) for (int i = int(a); i <= int(b); i++)
#define ford(i,a,b) for (int i = int(a); i >= int(b); i--)
#define ll int64_t
#define sz(x) int(x.size())

using namespace std;
template<class t, class u> bool maxi(t &a, u b){ if (a < b){ a = b; return 1;} return 0;}
template<class t, class u> bool mini(t &a, u b){ if (a > b){ a = b; return 1;} return 0;}

int main() {
    // freopen("input.txt","r",stdin);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int nTest; cin >> nTest;
    while (nTest--) {
        int n; cin >> n;
        vector<vector<int> > adj(n);
        vector<vector<ll> > cost(n, vector<ll>(2));
        vector<vector<ll> > dp(n, vector<ll>(2, 0));
        rep(i,n) {
            cin >> cost[i][0] >> cost[i][1];
        }
        rep(i,n-1) {
            int u, v; cin >> u >> v;
            --u; --v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        function<void(int,int)> dfs = [&] (int u, int p) {
            for(int v: adj[u]) {
                if (v == p) continue;
                dfs(v, u);
                dp[u][0] += max(dp[v][1] + abs(cost[u][0] - cost[v][1]), dp[v][0] + abs(cost[u][0] - cost[v][0]));
                dp[u][1] += max(dp[v][0] + abs(cost[u][1] - cost[v][0]), dp[v][1] + abs(cost[u][1] - cost[v][1]));
            }
        };
        dfs(0, -1);
        cout << max(dp[0][1], dp[0][0]) << '\n';
    }
    return 0;
}