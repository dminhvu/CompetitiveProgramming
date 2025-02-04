#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < int(n); i++)
#define fore(i,a,b) for (int i = int(a); i <= int(b); i++)
#define ford(i,a,b) for (int i = int(a); i >= int(b); i--)
#define ll int64_t
#define sz(x) int(x.size())

using namespace std;
template<class t, class u> bool maxi(t &a, u b){ if (a < b){ a = b; return 1;} return 0;}
template<class t, class u> bool mini(t &a, u b){ if (a > b){ a = b; return 1;} return 0;}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, x; cin >> n >> x;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    multiset<int> ms;
    rep(i,n) ms.insert(a[i]);
    int ans = 0;
    while (ms.size()) {
        ans += 1;
        int cur = *ms.begin();
        ms.erase(ms.begin());
        auto it = ms.upper_bound(x - cur);
        if (it != ms.begin()) {
            --it;
            ms.erase(it);
        }
    }
    cout << ans;
    return 0;
}