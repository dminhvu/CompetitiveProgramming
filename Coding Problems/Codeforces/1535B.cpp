#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < int(n); i++)
#define fore(i,a,b) for (int i = int(a); i <= int(b); i++)
#define ford(i,a,b) for (int i = int(a); i >= int(b); i--)
#define ll int64_t
#define sz(x) int(x.size())

using namespace std;
template<class t, class u> bool maxi(t &a, u b){ if (a < b){ a = b; return 1;} return 0;}
template<class t, class u> bool mini(t &a, u b){ if (a > b){ a = b; return 1;} return 0;}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int nTest; cin >> nTest;
    while (nTest--) {
        int n; cin >> n;
        vector<int> a(n);
        rep(i,n) cin >> a[i];
        sort(a.begin(), a.end(), [] (int x, int y) {
            return x % 2 < y % 2;
        });
        int ans = 0;
        rep(i,n) {
            rep(j,n) {
                if (j <= i) continue;
                ans += __gcd(a[i], a[j] * 2) > 1;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}