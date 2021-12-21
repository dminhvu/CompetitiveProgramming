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
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n);
        rep(i,n) cin >> a[i];
        sort(a.begin(), a.end());
        vector<int> ans;
        bool f = 0;
        while (sz(a)) {
            if (!f) {
                ans.pb(a.back());
                a.pop_back();
            } else {
                ans.pb(a[0]);
                a.erase(a.begin());
            }
            f ^= 1;
        }
        while (sz(ans)) {
            cout << ans.back() << " ";
            ans.pop_back();
        }
        cout << '\n';
    }
    return 0;
}