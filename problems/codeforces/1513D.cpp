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

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int nTest; cin >> nTest;
    while (nTest--) {
        int n, p; cin >> n >> p;
        vector<pair<int, int> > a(n);
        vector<int> c(n);
        vector<bool> connected(n, 0);
        rep(i,n) {
            cin >> a[i].first;
            a[i].second = i;
            c[i] = a[i].first;
        }
        sort(a.begin(), a.end());
        ll res = 0;
        rep(i,n) {
            int weight = a[i].first;
            int pos = a[i].second;
            if (weight >= p) break;
            for(int j = pos; j > 0 && !connected[j - 1] && c[j - 1] % weight == 0; j--) {
                res += 1ll * weight;
                connected[j - 1] = 1;
            }
            for(int j = pos; j < n - 1 && !connected[j] && c[j + 1] % weight == 0; j++) {
                res += 1ll * weight;
                connected[j] = 1;
            }
        }
        rep(i,n-1) res += 1ll * (!connected[i] ? p : 0);
        cout << res << '\n';
    }
    return 0;
}