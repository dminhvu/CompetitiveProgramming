#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < int(n); i++)
#define fore(i,a,b) for (int i = int(a); i <= int(b); i++)
#define ford(i,a,b) for (int i = int(a); i >= int(b); i--)
#define ll int64_t
#define sz(x) int(x.size())

using namespace std;
template<class t, class u> bool maxi(t &a, u b){ if (a < b){ a = b; return 1;} return 0;}
template<class t, class u> bool mini(t &a, u b){ if (a > b){ a = b; return 1;} return 0;}

map<pair<int, int>, int> mp;
vector<vector<int> > adj;

bool dfs(int u, int p = -1, int x = 2) {
    int cnt = 0;
    bool ans = true;
    for (int v: adj[u]) {
        cnt += 1;
        if (v == p) {
            continue;
        }
        if (p != -1) {
            mp[{u, v}] = mp[{v, u}] = 5 - mp[{u, p}];
        } else {
            if (cnt & 1) {
                mp[{u, v}] = mp[{v, u}] = x;
            } else {
                mp[{u, v}] = mp[{v, u}] = 5 - x;
            }
        }
        ans &= dfs(v, u, 5 - x);
    }
    ans &= cnt <= 2;
    return ans;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int nTest; cin >> nTest;
    while (nTest--) {
        int n; cin >> n;
        mp.clear();
        adj.clear();
        adj.resize(n);
        vector<pair<int, int> > e;
        rep(i,n-1) {
            int u, v; cin >> u >> v;
            --u; --v;
            adj[u].push_back(v);
            adj[v].push_back(u);
            e.push_back({u, v});
        }
        if (dfs(0)) {
            for (pair<int, int> p: e) {
                cout << mp[p] << " ";
            }
        } else {
            cout << -1;
        }
        cout << '\n';
    }
    return 0;
}