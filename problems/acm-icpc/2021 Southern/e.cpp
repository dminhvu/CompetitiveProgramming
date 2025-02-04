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
const double eps = 1e-9;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // freopen("input.txt","r",stdin);
    int a, h; cin >> a >> h;
    double ans = 0;
    double range1 = 1.0 * h / 6.0; // 0 -> A
    double range2 = 1.0 * h / 3.0; // A -> 100
    int cnt = 0;
    double l = 0, r = h / 6.0;
    while (fabs(l - r) > eps) {
        double x1 = l + (r - l) / 3.0;
        double x2 = r - (r - l) / 3.0;
        double p1 = 6.0 * a * x1 * (1.0 * h - x1) / (1.0 * h);
        double p2 = 6.0 * a * x2 * (1.0 * h - x2) / (1.0 * h);
        if (p1 - p2 > eps) {
            r = x2;
        } else {
            l = x1;
        }
        ans = max(ans, p1);
        ans = max(ans, p2);
    }
    l = h / 6.0, r = h / 3.0;
    while (fabs(l - r) > eps) {
        double x1 = l + (r - l) / 3.0;
        double x2 = r - (r - l) / 3.0;
        double p1 = (6.0 * (100.0 - 1.0 * a) * x1 / (1.0 * h) + 2.0 * a - 100.0) * (1.0 * h - x1);
        double p2 = (6.0 * (100.0 - 1.0 * a) * x2 / (1.0 * h) + 2.0 * a - 100.0) * (1.0 * h - x2);
        if (p1 - p2 > eps) {
            r = x2;
        } else {
            l = x1;
        }
        ans = max(ans, p1);
        ans = max(ans, p2);
    }
    ans = max(ans, 100.0 * (1.0 * h - 1.0 * h / 3.0));
    cout << fixed << setprecision(8) << ans;
    return 0;
}