/*
Task: 
Date: 
Author: aLittleLove (Minh Vu)
*/

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
const int mod = 1e9 + 7;
const double pi = atan(1) * 4.0;
template<typename T, typename U> inline void mini(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> inline void maxi(T &x, U y) { if(x < y) x = y; }

i64 _pow(i64 x, i64 y)
{
    if (y==0) return 1;
    i64 tmp = _pow(x, y>>1ll);
    if (y&1) return (tmp%mod * tmp%mod * x%mod)%mod;
    return (tmp%mod * tmp%mod)%mod;
}

i64 gcd(i64 a, i64 b)
{
    if (a==0) return b;
    return gcd(b%a, a);
}

void Solve()
{
    int n, m; cin >> n >> m;
    vector<i64> a(n), b(m);
    rep(i,n) cin >> a[i];
    rep(i,m) cin >> b[i];
    if (n==1)
    {
        rep(i,m) cout << a[0] + b[i] << " ";
        return;
    }
    sort(a.begin(), a.end());
    i64 g = a[1] - a[0];
    rep(i,n)
    {
        if (i==n-1) break;
        g = gcd(g, a[i + 1] - a[0]);
    }
    //cout << g << '\n';
    rep(i,m)
    {
        cout << gcd(g, a[0] + b[i]) << " ";
    }
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("input.txt","r",stdin);
    int nTest; //cin >> nTest;
    nTest = 1;
    while (nTest--) Solve();

    return 0;
}