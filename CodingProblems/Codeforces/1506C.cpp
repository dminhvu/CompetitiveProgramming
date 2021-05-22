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
const int inf = 1e9;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--) {
        string a, b; cin >> a >> b;
        int n = sz(a), m = sz(b);
        a = ' ' + a;
        b = ' ' + b;
        int ans = inf;
        fore(i,1,n) {
            fore(j,i,n+1) {
                fore(k,1,m) {
                    fore(l,k,m+1) {
                        string sa = a.substr(i, j - i);
                        string sb = b.substr(k, l - k);
                        if (sa == sb) mini(ans, n + m - sz(sa) - sz(sb));
                    }
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}