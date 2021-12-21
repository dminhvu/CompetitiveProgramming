#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < int(n); i++)
#define fore(i,a,b) for (int i = int(a); i <= int(b); i++)
#define ford(i,a,b) for (int i = int(a); i >= int(b); i--)
#define ll int64_t
#define pb push_back
#define fi first
#define se second
#define sz(x) int(x.size())

using namespace std;
template<class t, class u> bool maxi(t &a, u b){ if (a < b){ a = b; return 1;} return 0;}
template<class t, class u> bool mini(t &a, u b){ if (a > b){ a = b; return 1;} return 0;}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("input.txt","r",stdin);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<pair<int, int> > a(n);
        rep(i,n) {
            cin >> a[i].fi;
            a[i].se = i;
        }
        int ans = 0;
        vector<pair<int, int> > v;
        while (a.size()) {
            // for(auto [x, y]: v) cout << x << " ";
            // cout << '\n';
            int minVal = min(a[0].fi, a.back().fi);
            int id = (a[0].fi <= a.back().fi ? a[0].se : a.back().se);
            if (a[0].fi <= a.back().fi) a.erase(a.begin());
            else a.pop_back();
            if (v.empty()) {
                v.pb({minVal, id});
                continue;
            }
            while (sz(v) && minVal < v.back().fi) {
                maxi(ans, id);
                v.pop_back();
            }
            v.pb({minVal, id});
        }
        cout << ans << '\n';
    }
    return 0;
}