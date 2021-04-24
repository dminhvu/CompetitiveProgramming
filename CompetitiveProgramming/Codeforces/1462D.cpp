#include<bits/stdc++.h>
#define rep(i,n) for (int i=0, _n=n; i<_n; i++)
#define FOR(i,a,b) for (int _a=(a), _b=(b), i=_a; _a<=_b?i<=_b:i>=_b; _a<=_b?i++:i--)
#define _mem(a, b) memset(a, (b), sizeof(a))
#define pb push_back
#define fi first
#define se second
#define sz(a) int((a).size())

using namespace std;
const int N = 3e3 + 5;
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

int n;
int a[N];

void Solve()
{
    cin >> n;
    for (int i=1; i<=n; i++) cin >> a[i];
    int ans = n - 1, sum = accumulate(a+1,a+n+1,0);
    for (int i=n; i>=1; i--)
    {
        if (sum%i!=0) continue;
        bool f = 1;
        int cur = 0;
        for (int j=1; j<=n; j++)
        {
            cur += a[j];
            if (cur==sum/i)
            {
                cur = 0;
                continue;
            }
            if (cur>sum/i)
            {
                f = 0;
                break;
            }
        }
        if (cur!=0 && cur==sum/i) f = 1;
        if (f) 
        {
            cout << n - i << '\n';
            return;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("input.txt","r",stdin);
    int nTest; cin >> nTest;
    while (nTest--) Solve();

    return 0;
}