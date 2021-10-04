#include<bits/stdc++.h>
#define rep(i,n) for (int i=0, _n=n; i<_n; i++)
#define FOR(i,a,b) for (int _a=(a), _b=(b), i=_a; _a<=_b?i<=_b:i>=_b; _a<=_b?i++:i--)
#define _mem(a, b) memset(a, (b), sizeof(a))
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

ll dp[100][100];

ll calc(int k, int n) {
    if (n == k) return 1;
    if (k == 0) return 1;
    if (k == 1) return n;
    if (dp[k][n] != -1) return dp[k][n];
    return dp[k][n] = calc(k - 1, n - 1) + calc(k, n - 1);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // freopen("input.txt","r",stdin);
    memset(dp,-1,sizeof dp);
    int n; cin >> n;
    ll ans = 0;
    ll sum = 0;
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= i; j++) {
            ans += calc(j, i);
        }
    }
    for(int i = 0; i <= n; i++) {
        sum += calc(i, n);
    }
    cout << sum << " " << ans << '\n';
    return 0;
}