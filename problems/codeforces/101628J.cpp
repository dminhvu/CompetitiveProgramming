#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < int(n); i++)
#define fore(i,a,b) for (int i = int(a); i <= int(b); i++)
#define ford(i,a,b) for (int i = int(a); i >= int(b); i--)
#define ll int64_t
#define sz(x) int(x.size())

using namespace std;
template<class t, class u> bool maxi(t &a, u b){ if (a < b){ a = b; return 1;} return 0;}
template<class t, class u> bool mini(t &a, u b){ if (a > b){ a = b; return 1;} return 0;}
const ll inf = 1e18 + 5;

struct Data {
    int x, y, z;
    bool operator < (const Data &oth) const {
        return z < oth.z;
    }
};

ll calc(vector<Data> a, int mid) {
    int n = sz(a);
    ll cost = 0, diff = 0;
    rep(i,n) {
        if (a[i].x <= mid) continue;
        diff += a[i].x - mid;
        cost += 1ll * (a[i].x - mid) * a[i].y;
    }
    rep(i,n) {
        if (a[i].x > mid) continue;
        ll mn = min(diff, (ll)(mid - a[i].x));
        diff -= mn;
        cost += mn * a[i].z;
    }
    return cost;
}

int main() {
    // freopen64("input.txt","r",stdin);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    ll k; cin >> k;
    vector<Data> a;
    rep(i,n) {
        int x, y, z; cin >> x >> y >> z;
        a.push_back({x, y, z});
    }
    sort(a.begin(), a.end());
    int l = 0, r = (int)1e6 + 5;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (k - calc(a, mid) >= 0) {
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    cout << l;
    return 0;
}