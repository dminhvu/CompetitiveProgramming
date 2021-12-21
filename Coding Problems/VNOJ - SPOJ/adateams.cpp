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
const int N = 1e6 + 5;

vector<int> fac, inv;
int binpow(int n, int k) {
    if (k == 0) return 1;
    int tmp = binpow(n, k / 2);
    tmp = (1ll * tmp % mod * tmp % mod) % mod;
    if (k & 1) tmp = (1ll * tmp % mod * n % mod) % mod;
    return tmp;
}

int C(int n, int k) {
    return (1ll * fac[n] % mod * inv[k] % mod * inv[n - k] % mod) % mod;
}

int main() {
    // freopen64("input.txt","r",stdin);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    fac.push_back(1);
    inv.push_back(1);
    fore(i,1,N-1) {
        fac.push_back((1ll * fac[i - 1] % mod * i % mod) % mod);
        inv.push_back(binpow(fac[i], mod - 2));
    }
    int n, a, b, d;
    while (cin >> n >> a >> b >> d) {
        cout << (1ll * C(n, a) % mod * binpow(C(b, d), a) % mod) % mod << '\n';
    }
    return 0;
}