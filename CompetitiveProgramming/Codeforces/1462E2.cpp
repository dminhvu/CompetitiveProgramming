#include<bits/stdc++.h>
#define rep(i,n) for (int i=0, _n=n; i<_n; i++)
#define FOR(i,a,b) for (int _a=(a), _b=(b), i=_a; _a<=_b?i<=_b:i>=_b; _a<=_b?i++:i--)
#define _mem(a, b) memset(a, (b), sizeof(a))
#define pb push_back
#define fi first
#define se second
#define sz(a) int((a).size())

using namespace std;
typedef long long ll;
typedef int64_t i64;
typedef pair<int, int> pii;
typedef vector<pii> vii;
typedef vector<int> vi;
const int N = 2e5 + 5;
const int inf = 1e9;
const i64 mod = 1e9 + 7;
const double pi = atan(1) * 4.0;
template<typename T, typename U> inline void mini(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> inline void maxi(T &x, U y) { if(x < y) x = y; }

i64 _pow(i64 x, i64 y)
{
    if (y==0) return 1;
    i64 tmp = _pow(x, y/2ll);
    if (y&1) return (tmp%mod * tmp%mod * x%mod)%mod;
    return (tmp%mod * tmp%mod)%mod;
}

int a[N];
i64 fact[N], invFact[N];

i64 C(int n, int k)
{
    if (k>n) return 0;
    return fact[n] * invFact[k] % mod * invFact[n - k] % mod;
}

void Solve()
{
    int n, m, k;
    i64 ans = 0;
    cin >> n >> m >> k;
    rep(i,n) cin >> a[i];
    sort(a, a+n);
    for (int i=0; i<n; i++)
    {
        int l = i + 1;
        int r = upper_bound(a,a+n,a[i]+k) - a;
        ans = (ans + C(r - l, m - 1))%mod;
    }
    cout << ans << '\n';

}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("input.txt","r",stdin);
    int nTest; cin >> nTest;
    fact[0] = invFact[0] = 1;
    for (int i=1; i<N; i++)
    {
        fact[i] = (fact[i - 1] * i) % mod;
        invFact[i] = _pow(fact[i], mod - 2);
    }
    while (nTest--) Solve();

    return 0;
}