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

ll calc(ll x) {
    ll minDigit = 10, maxDigit = 0;
    while (x) {
        mini(minDigit, x % 10ll);
        maxi(maxDigit, x % 10ll);
        x /= 10ll;
    }
    return minDigit * maxDigit;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--) {
        ll n, k; cin >> n >> k;
        --k;
        while (k--) {
            ll nextn = n + calc(n);
            // cout << nextn << " ";
            if (nextn == n) {
                break;
            }
            n = nextn;
        }
        cout << n << '\n';
    }
    return 0;
}