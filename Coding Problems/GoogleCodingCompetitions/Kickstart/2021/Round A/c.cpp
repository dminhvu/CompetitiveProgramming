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

struct myData {
    int u, v;
    ll w;
    bool operator < (const myData &oth) const {
        return w < oth.w;
    }
};

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("input.txt","r",stdin);
    int t; cin >> t;
    fore(nT,1,t) {
        int r, c; cin >> r >> c;
        vector<vector<ll> > a(r + 1, vector<ll>(c + 1, 0));
        priority_queue<myData> pq;
        fore(i,1,r) {
            fore(j,1,c) {
                cin >> a[i][j];
                pq.push({i, j, a[i][j]});
            }
        }
        vector<vector<bool> > fixed(r + 1, vector<bool>(c + 1, 0));
        ll ans = 0;
        while (pq.size()) {
            int u = pq.top().u;
            int v = pq.top().v;
            pq.pop();
            if (u > 1) {
                if (!fixed[u - 1][v]) {
                    if (a[u][v] - a[u - 1][v] > 1) {
                        ans += 1ll * abs(a[u - 1][v] - a[u][v]) - 1;
                        a[u - 1][v] = a[u][v] - 1;
                        pq.push({u - 1, v, a[u - 1][v]});
                    }
                }
            }
            if (u < r) {
                if (!fixed[u + 1][v]) {
                    if (a[u][v] - a[u + 1][v] > 1) {
                        ans += 1ll * abs(a[u + 1][v] - a[u][v]) - 1;
                        a[u + 1][v] = a[u][v] - 1;
                        pq.push({u + 1, v, a[u + 1][v]});
                    }
                }
            }
            if (v > 1) {
                if (!fixed[u][v - 1]) {
                    if (a[u][v] - a[u][v - 1] > 1) {
                        ans += 1ll * abs(a[u][v - 1] - a[u][v]) - 1;
                        a[u][v - 1] = a[u][v] - 1;
                        pq.push({u, v - 1, a[u][v - 1]});
                    }
                }
            }
            if (v < c) {
                if (!fixed[u][v + 1]) {
                    if (a[u][v] - a[u][v + 1] > 1) {
                        ans += 1ll * abs(a[u][v + 1] - a[u][v]) - 1;
                        a[u][v + 1] = a[u][v] - 1;
                        pq.push({u, v + 1, a[u][v + 1]});
                    }
                }
            }
        }
        cout << "Case #" << nT << ": " << ans << '\n';
    }
    return 0;
}