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

vector<int> pa, siz;

int root(int x) {
    return x == pa[x] ? pa[x] : pa[x] = root(pa[x]);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, q; cin >> n >> q;
    vector<int> c(n + 1);
    pa.resize(n + 1);
    siz.resize(n + 1, 1);
    vector<map<int, int> > cnt(n + 1);
    rep(i,n) {
        cin >> c[i + 1];
        pa[i + 1] = i + 1;
        cnt[i + 1][c[i + 1]]++;
    }
    while (q--) {
        int t, u, v; cin >> t >> u >> v;
        if (t == 1) {
            u = root(u);
            v = root(v);
            if (u != v) {
                if (siz[u] < siz[v]) swap(u, v);
                pa[v] = u;
                siz[u] += siz[v];
                for(auto [x, y]: cnt[v]) {
                    cnt[u][x] += y;
                }
                cnt[v].clear();
            }
        } else {
            u = root(u);
            cout << cnt[u][v] << '\n';
        }
    }
    return 0;
}