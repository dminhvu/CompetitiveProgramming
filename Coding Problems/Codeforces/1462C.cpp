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

void Solve()
{
    int x; cin >> x;
    if (x>45)
    {
        cout << "-1\n";
        return;
    }
    int curmax = 9, sum = 0;
    vector<int> ans;
    while (x--)
    {
        if (sum!=curmax) sum++;
        else 
        {
            ans.pb(sum);
            curmax--;
            sum = 1;
        }
    }
    if (sum!=0) ans.pb(sum);
    reverse(ans.begin(), ans.end());
    for (int x: ans) cout << x;
    cout << '\n';
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("input.txt","r",stdin);
    int nTest; cin >> nTest;
    while (nTest--) Solve();

    return 0;
}