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
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n);
        rep(i,n) cin >> a[i];
        int ans = 0;
        fore(i,0,100) {
            vector<bool> fixed(n, 0);
            int cnt = 0;
            rep(j,n) {
                rep(k,n) {
                    if (j != k && a[j] + a[k] == i && !fixed[j] && !fixed[k]) {
                        cnt++;
                        fixed[j] = 1;
                        fixed[k] = 1;
                        // cout << j << " " << k << '\n';
                    }
                }
            }
            maxi(ans,cnt);
        }
        cout << ans << '\n';
    }
    return 0;
}