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
    int n; cin >> n;
    string s; cin >> s;
    if (s[0]=='2' && s[1]=='0' && s[2]=='2' && s[3]=='0') cout << "YES\n";
    else if (s[0]=='2' && s[1]=='0' && s[2]=='2' && s[n - 1]=='0') cout << "YES\n";
    else if (s[0]=='2' && s[1]=='0' && s[n - 2]=='2' && s[n - 1]=='0') cout << "YES\n";
    else if (s[0]=='2' && s[n - 3]=='0' && s[n - 2]=='2' && s[n - 1]=='0') cout << "YES\n";
    else if (s[n - 4]=='2' && s[n - 3]=='0' && s[n - 2]=='2' && s[n - 1]=='0') cout << "YES\n";
    else cout << "NO\n";
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("input.txt","r",stdin);
    int nTest; cin >> nTest;
    while (nTest--) Solve();

    return 0;
}