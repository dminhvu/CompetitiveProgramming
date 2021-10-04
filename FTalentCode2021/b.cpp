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

struct Data {
    string name;
    ll cost, sum;
    bool operator < (const Data &oth) {
        return oth.cost * oth.sum < cost * sum;
    }
};

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // freopen("input.txt","r",stdin);
    int n; cin >> n;
    vector<Data> a(n);
    rep(i,n) {
        cin >> a[i].name >> a[i].cost >> a[i].sum;
        for(int j = 0; j < a[i].name.size(); j++) {
            if (a[i].name[j] >= 'A' && a[i].name[j] <= 'Z') {
                a[i].name[j] += 32;
            }
        }
    }
    sort(a.begin(), a.end());
    vector<ll> pref(n, 0ll);
    rep(i,n) {
        pref[i] = a[i].cost * a[i].sum;
        if (i) pref[i] += pref[i - 1];
    }
    vector<string> ans;
    int cnt = -1;
    rep(i,n) {
        if (5ll * pref[i] >= 4ll * pref[n - 1] && 5 * (i + 1) <= n) {
            cnt = i;
        }
    }
    rep(i,cnt+1) ans.push_back(a[i].name);
    sort(ans.begin(), ans.end());
    cout << "{";
    rep(i,ans.size()) {
        cout << ans[i];
        if (i != ans.size() - 1) cout << ",";
    }
    cout << "}";
    return 0;
}