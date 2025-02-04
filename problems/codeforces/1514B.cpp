#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < int(n); i++)
#define fore(i,a,b) for (int i = int(a); i <= int(b); i++)
#define ford(i,a,b) for (int i = int(a); i >= int(b); i--)
#define ll int64_t
#define sz(x) int(x.size())

using namespace std;
template<class t, class u> bool maxi(t &a, u b){ if (a < b){ a = b; return 1;} return 0;}
template<class t, class u> bool mini(t &a, u b){ if (a > b){ a = b; return 1;} return 0;}
const int mod = 1e9 + 7;

int binpow(int n, int k) {
    if (k == 0) return 1;
    int tmp = binpow(n, k / 2);
    tmp = 1ll * tmp * tmp % mod;
    if (k & 1) tmp = 1ll * tmp * n % mod;
    return tmp;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int nTest; cin >> nTest;
    while (nTest--) {
        int n, k; cin >> n >> k;
        cout << binpow(n, k) << '\n';
    }
    return 0;
}