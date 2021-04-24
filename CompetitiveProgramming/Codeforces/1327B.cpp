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
        vector<vector<int> > a(n);
        rep(i,n) {
            int k; cin >> k;
            rep(j,k) {
                int x; cin >> x;
                --x;
                a[i].pb(x);
            }
        }
        vector<bool> f(n, 0), opt(n, 0);
        rep(i,n) {
            bool found = 0;
            rep(j,sz(a[i])) {
                if (!f[a[i][j]]) {
                    f[a[i][j]] = 1;
                    found = 1;
                    break;
                }
            }
            opt[i] = found;
        }
        bool final = 1;
        rep(i,n) final &= opt[i];
        if (final) {
            cout << "OPTIMAL\n";
            continue;
        }
        int num = n - 1;
        while (num >= 0 && f[num]) num--;
        if (num == -1) {
            cout << "OPTIMAL\n";
            continue;
        }
        rep(i,n) {
            if (opt[i]) continue;
            bool f = 1;
            rep(j,sz(a[i])) {
                f &= (a[i][j] != num);
            }
            if (f) {
                final = 1;
                cout << "IMPROVE\n";
                cout << i + 1 << " " << num + 1 << '\n';
                break;
            }
        }
        if (!final) cout << "OPTIMAL\n";
    }
    return 0;
}