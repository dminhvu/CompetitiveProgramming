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
        vector<int> a(n), b(n);
        rep(i,n) cin >> a[i] >> b[i];
        bool f = 1;
        rep(i,n) {
            f &= (b[i] <= a[i]);
            if (i) {
                f &= a[i] >= a[i - 1];
                f &= b[i] >= b[i - 1];
                f &= (b[i] - b[i - 1] <= a[i] - a[i - 1]);
            }
        }
        cout << (f ? "YES\n" : "NO\n");
    }
    return 0;
}