#include<bits/stdc++.h>
#define rep(i,n) for (int i=0, _n=n; i<_n; i++)
#define FOR(i,a,b) for (int _a=(a), _b=(b), i=_a; _a<=_b?i<=_b:i>=_b; _a<=_b?i++:i--)
#define _mem(a, b) memset(a, (b), sizeof(a))
#define pb push_back
#define fi first
#define se second
#define sz(a) int((a).size())

using namespace std;
const int N = 2e5 + 5;
const int inf = 1e9;
const int mod = 1e9 + 7;
const double pi = atan(1) * 4.0;
typedef long long ll;
typedef int64_t i64;
typedef pair<int, int> pii;
typedef vector<pii> vii;
typedef vector<int> vi;
template<typename T, typename U> inline void mini(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> inline void maxi(T &x, U y) { if(x < y) x = y; }

i64 n;
i64 POW(i64 x, i64 y)
{
    if (y==0) return 1;
    i64 tmp = POW(x, y/2);
    if (y&1) return tmp*tmp*x;
    return tmp*tmp;
}

void Solve()
{
    cin >> n;
    i64 cur = n;
    vector<i64> ans;
    i64 base, mx = -1, rem;
    for (i64 i=2; i*i<=n; i++)
    {
        if (n%i==0)
        {
            for (i64 j=1; j; j++)
            {
                i64 p = POW(i, j);
                if (p>n) break;
                if (n%p==0 && (n/p)%i==0 && j>mx)
                {
                    mx = j;
                    base = i;
                    rem = n/p;
                }
            }
        }
    }
    if (mx==-1) cout << 1 << '\n' << n << '\n';
    else 
    {
        for (int i=1; i<=mx; i++) ans.pb(base);
        if (rem!=1) ans.pb(rem);
        cout << sz(ans) << '\n';
        for (i64 x: ans) cout << x << " ";
        cout << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // freopen("input.txt","r",stdin);
    int nTest; cin >> nTest;
    while (nTest--) Solve();

    return 0;
}