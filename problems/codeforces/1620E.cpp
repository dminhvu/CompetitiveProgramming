#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < int(n); i++)
#define fore(i,a,b) for (int i = int(a); i <= int(b); i++)
#define ford(i,a,b) for (int i = int(a); i >= int(b); i--)
#define ll int64_t
#define sz(x) int(x.size())

using namespace std;
template<class t, class u> bool maxi(t &a, u b){ if (a < b){ a = b; return 1;} return 0;}
template<class t, class u> bool mini(t &a, u b){ if (a > b){ a = b; return 1;} return 0;}
const int N = 5e5 + 5;

int main() {
    // freopen("input.txt","r",stdin);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int q; cin >> q;
    vector<vector<int> > query(q);
    rep(i,q) {
        int t; cin >> t;
        query[i].push_back(t);
        if (t == 1) {
            int u; cin >> u;
            query[i].push_back(u);
        } else {
            int u, v; cin >> u >> v;
            query[i].push_back(u);
            query[i].push_back(v);
        }
    }
    vector<int> par(N), ans;
    rep(i,N) par[i] = i;
    ford(i,q-1,0) {
        if (query[i][0] == 1) {
            ans.push_back(par[query[i][1]]);
        } else {
            int u = query[i][1], v = query[i][2];
            par[u] = par[v];
        }
    }
    reverse(ans.begin(), ans.end());
    for(int x: ans) cout << x << " ";
    return 0;
}