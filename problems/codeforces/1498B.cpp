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
        int n, w; cin >> n >> w;
        int ans = 1;
        multiset<int> ms;
        rep(i,n) {
            int x; cin >> x;
            ms.insert(x);
        }
        int rem = w;
        while (ms.size()) {
            auto it = ms.upper_bound(rem);
            if (it != ms.begin()) {
                --it;
                rem -= *it;
                ms.erase(it);
            } else {
                ans += 1;
                rem = w;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}