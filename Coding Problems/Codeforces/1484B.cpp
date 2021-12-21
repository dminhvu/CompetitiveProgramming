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
    freopen("input.txt","r",stdin);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<ll> a(n + 1);
        rep(i,n) cin >> a[i + 1];
        vector<ll> b(n + 1, 0);
        rep(i,n-1) b[i + 1] = a[i + 2] - a[i + 1];
        bool pos = 0, neg = 0;
        rep(i,n-1) {
            pos |= (b[i + 1] >= 0);
            neg |= (b[i + 1] < 0);
        }
        if (pos && !neg) {
            bool f = 1;
            rep(i,n-1) {
                f &= (b[i + 1] == b[1]);
            }
            if (f) {
                cout << 0 << '\n';
            } else {
                cout << -1 << '\n';
            }
        } else if (!pos && neg) {
            bool f = 1;
            rep(i,n-1) {
                f &= (b[i + 1] == b[1]);
            }
            if (f) {
                cout << 0 << '\n';
            } else {
                cout << -1 << '\n';
            }
        } else {
            ll m = -1, diff = -1;
            rep(i,n) if (b[i + 1] >= 0) {
                diff = b[i + 1];
                break;
            }
            rep(i,n) {
                if (b[i + 1] < 0) {
                    if (m == -1) {
                        m = abs(b[i + 1] - diff);
                        break;
                    }
                }
            }
            vector<ll> c(n + 1, 0);
            c[1] = a[1] % m;
            bool f = 1;
            fore(i,1,n-1) {
                c[i + 1] = (c[i] + diff) % m;   
            }
            rep(i,n) f &= (c[i + 1] == a[i + 1]);
            if (f) cout << m << " " << diff << '\n';
            else cout << -1 << '\n';
        }
    }
    return 0;  
}