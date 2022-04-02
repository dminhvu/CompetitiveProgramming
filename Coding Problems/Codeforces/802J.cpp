#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < int(n); i++)
#define fore(i,a,b) for (int i = int(a); i <= int(b); i++)
#define ford(i,a,b) for (int i = int(a); i >= int(b); i--)
#define ll int64_t
#define sz(x) int(x.size())

using namespace std;
template<class t, class u> bool maxi(t &a, u b){ if (a < b){ a = b; return 1;} return 0;}
template<class t, class u> bool mini(t &a, u b){ if (a > b){ a = b; return 1;} return 0;}

vector<vector<pair<int, int> > > adj;

int dfs(int u, int p = -1) {
    int ans = 0;
    for (pair<int, int> pi: adj[u]) {
        int v = pi.first;
        if (v == p) continue;
        int c = pi.second;
        ans = max(ans, dfs(v, u) + c);
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    adj.resize(n);
    rep(i,n-1) {
        int u, v, c; cin >> u >> v >> c;
        adj[u].push_back({v, c});
        adj[v].push_back({u, c});
    }

    cout << dfs(0);
    return 0;
}