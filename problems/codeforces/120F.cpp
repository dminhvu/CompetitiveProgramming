#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < int(n); i++)
#define fore(i,a,b) for (int i = int(a); i <= int(b); i++)
#define ford(i,a,b) for (int i = int(a); i >= int(b); i--)
#define ll int64_t
#define sz(x) int(x.size())

using namespace std;
template<class t, class u> bool maxi(t &a, u b){ if (a < b){ a = b; return 1;} return 0;}
template<class t, class u> bool mini(t &a, u b){ if (a > b){ a = b; return 1;} return 0;}

pair<int, int> dfs(vector<vector<int> > adj, int u, int p = -1) {
    pair<int, int> cur = {u, 0};
    for(int v: adj[u]) {
        if (v == p) continue;
        pair<int, int> nxt = dfs(adj, v, u);
        if (nxt.second > cur.second) {
            cur = nxt;
        }
    }
    cur.second++;
    return cur;
}

int main() {
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int nTest; cin >> nTest;
    int ans = 0;
    while (nTest--) {
        int n; cin >> n;
        vector<vector<int> > adj(n);
        rep(i,n-1) {
            int u, v; cin >> u >> v;
            adj[u - 1].push_back(v - 1);
            adj[v - 1].push_back(u - 1);
        }
        pair<int, int> u = dfs(adj, 0);
        pair<int, int> v = dfs(adj, u.first);
        ans += v.second - 1;
    }
    cout << ans << '\n';
    return 0;
}