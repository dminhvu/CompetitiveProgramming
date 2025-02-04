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
    int n; cin >> n;
    vector<pair<int, int> > a(n);
    rep(i,n) cin >> a[i].first >> a[i].second;
    sort(a.begin(), a.end());
    ll ans = 0;
    ll curtime = 0;
    rep(i,n) {
        curtime += a[i].first;
        ans += (a[i].second - curtime);
    }
    cout << ans;
    return 0;
}