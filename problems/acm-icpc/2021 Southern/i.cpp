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
const int N = 1e6 + 5;
const int inf = 1e9;
const int mod = 1e9 + 7;
const double pi = atan(1) * 4.0;
template<typename T, typename U> inline void mini(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> inline void maxi(T &x, U y) { if(x < y) x = y; }


ll a[N], lower[N], upper[N], lowerTree[N<<2], upperTree[N<<2];

void addLower(int id, int l, int r, int p) {
    if (l > r) return;
    if (p < l || p > r) return;
    lowerTree[id] += 1;
    if (l == r) return;

    int mid = l + (r - l) / 2;
    addLower(id*2, l, mid, p);
    addLower(id*2+1, mid+1, r, p);
}

void addUpper(int id, int l, int r, int p) {
    if (l > r) return;
    if (p < l || p > r) return;
    upperTree[id] += 1;
    if (l == r) return;

    int mid = l + (r - l) / 2;
    addUpper(id*2, l, mid, p);
    addUpper(id*2+1, mid+1, r, p);
}


int getLower(int id, int l, int r, int u, int v) {
    if (l > r) return 0;
    if (v < l || u > r) return 0;
    if (u <= l && r <= v) {
        return lowerTree[id];
    }

    int mid = l + (r - l) / 2;

    return getLower(id*2, l, mid, u, v) + getLower(id*2+1, mid+1, r, u, v);
}

int getUpper(int id, int l, int r, int u, int v) {
    if (l > r) return 0;
    if (v < l || u > r) return 0;
    if (u <= l && r <= v) {
        return upperTree[id];
    }

    int mid = l + (r - l) / 2;

    return getUpper(id*2, l, mid, u, v) + getUpper(id*2+1, mid+1, r, u, v);
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    memset(lower,0,sizeof lower);
    memset(upper,0,sizeof upper);
    memset(upperTree,0,sizeof upperTree);
    memset(lowerTree,0,sizeof lowerTree);

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = n; i >= 1; --i) {
        addUpper(1, 1, n, a[i]);
        upper[a[i]] = getUpper(1, 1, n, 1, a[i]-1);
    }
    for (int i = 1; i <= n; ++i) {
        upper[i] += upper[i-1];
    }
    for (int i = 1; i <= n; ++i) {
        addLower(1, 1, n, a[i]);
        lower[a[i]] = getLower(1, 1, n, a[i]+1, n);
    }
    for (int i = n; i >= 1; --i) {
        lower[i] += lower[i+1];
    }
    ll ans = 1e18;
    for (int i = 1; i <= n; i++) {
        ans = min(ans, (ll)(upper[i-1]) + (ll)(lower[i+1]));
    }
    cout << ans;
    return 0;
}