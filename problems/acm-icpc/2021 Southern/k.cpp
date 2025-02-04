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

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // freopen("input.txt","r",stdin);
    int n; cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    ll y, z; cin >> y >> z;
    vector<ll> b(n);
    rep(i,n) {
        b[i] = abs(z - a[i]);
    }
    sort(b.begin(), b.end());
    ll sum = 0;
    int ans = 0;
    rep(i,n) {
        sum += b[i];
        ans = max(ans, i);
        if (sum >= abs(z - y)) {
            break;
        }
    }
    if (ans == 0) {
        ans = n;
    }
    cout << ans << '\n';
    return 0;
}