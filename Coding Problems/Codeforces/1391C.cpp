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
const ll mod = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<ll> fact(n + 1, 0), p2(n + 1, 0);
    fact[0] = 1;
    fore(i,1,n) {
        fact[i] = (fact[i - 1] % mod * 1ll * i) % mod;
    }
    p2[0] = 1;
    fore(i,1,n) {
        p2[i] = (p2[i - 1] * 2ll) % mod;
    }
    cout << (fact[n] - p2[n - 1] + mod * mod) % mod;
    return 0;
}