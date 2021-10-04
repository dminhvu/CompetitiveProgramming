#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < int(n); i++)
#define fore(i,a,b) for (int i = int(a); i <= int(b); i++)
#define ford(i,a,b) for (int i = int(a); i >= int(b); i--)
#define ll int64_t
#define sz(x) int(x.size())

using namespace std;
template<class t, class u> bool maxi(t &a, u b){ if (a < b){ a = b; return 1;} return 0;}
template<class t, class u> bool mini(t &a, u b){ if (a > b){ a = b; return 1;} return 0;}
const int64_t inf = 1e18;

int main() {
    // freopen64("input.txt","r",stdin);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, s; cin >> n >> s;
    multiset<int64_t> ms;
    vector<int64_t> a(n);
    rep(i,n) {
        cin >> a[i];
        ms.insert(a[i]);
    }
    int64_t ans = -inf;
    rep(i,n) {
        ms.erase(a[i]);
        int64_t min_element = *ms.begin();
        maxi(ans, min_element - s * 1ll * (i + 1));
        ms.insert(a[i]);
    }
    cout << ans << '\n';
    return 0;
}