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
    // freopen("input.txt","r",stdin);
    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        rep(i,k-3) cout << 1 << " ";
        n -= (k - 3);
        if (n % 3 == 0) {
            cout << n / 3 << " " << n / 3 << " " << n / 3 << '\n';
        } else if (n & 1) {
            cout << (n - 1) / 2 << " " << (n - 1) / 2 << " " << 1 << '\n';
        } else {
            if (n % 4 == 0) cout << n / 2 << " " << n / 4 << " " << n / 4 << '\n';
            else cout << (n - 2) / 2 << " " << (n - 2) / 2 << " " << 2 << '\n';
        }
    }
    return 0;
}