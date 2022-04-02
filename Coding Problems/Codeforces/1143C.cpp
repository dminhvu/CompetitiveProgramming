#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < int(n); i++)
#define fore(i,a,b) for (int i = int(a); i <= int(b); i++)
#define ford(i,a,b) for (int i = int(a); i >= int(b); i--)
#define ll int64_t
#define sz(x) int(x.size())

using namespace std;
template<class t, class u> bool maxi(t &a, u b){ if (a < b){ a = b; return 1;} return 0;}
template<class t, class u> bool mini(t &a, u b){ if (a > b){ a = b; return 1;} return 0;}

vector<vector<int> > adj;
vector<int> par, c;
vector<int> ans;

void dfs(int u) {
    bool is_not_respected = (c[u] == 1);
    for (int v: adj[u]) {
        is_not_respected &= (c[v] == 1);
    }
    if (is_not_respected) {
        ans.push_back(u);
    }
    for (int v: adj[u]) {
        dfs(v);
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    adj.resize(n);
    par.resize(n);
    c.resize(n);
    rep(i,n) {
        cin >> par[i] >> c[i];
        if (par[i] == -1) continue;
        --par[i];
        adj[par[i]].push_back(i);
    }
    rep(i,n) {
        if (par[i] == -1) {
            dfs(i);
        }
    }
    if (ans.empty()) cout << -1;
    sort(ans.begin(), ans.end());
    for (int x: ans) cout << x + 1 << " ";
    return 0;
}