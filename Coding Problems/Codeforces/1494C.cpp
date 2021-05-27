#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
#define fore(i,a,b) for (int i = (a); i <= (b); i++)
#define ford(i,a,b) for (int i = (a); i >= (b); i--)
#define ll int64_t
#define pb push_back
#define fi first
#define se second
#define sz(x) int(x.size())

using namespace std;
template<class t, class u> bool maxi(t &a, u b){ if (a < b){ a = b; return 1;} return 0;}
template<class t, class u> bool mini(t &a, u b){ if (a > b){ a = b; return 1;} return 0;}
const ll inf = 1e18;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<ll> a(n + 1), b(m + 2);
        b[0] = -inf;
        b[m + 1] = inf;
        fore(i,1,n) cin >> a[i];
        map<int, int> mp;
        fore(i,1,m) {
            cin >> b[i];
            mp[b[i]]++;
        }
        ll ansl = 0;
        int neg = 0, pos = 0;
        // fore(i,1,n) {
        //     neg += (a[i] < 0);
        //     pos += (a[i] > 0);
        // }
        vector<ll> dp(n + 2, 0);
        int l = 0;
        while (l + 1 < m && b[l + 1] < 0) l++;
        int r = l;
        ford(i,n,1) {
            if (a[i] > 0) continue;
            if (mp[a[i]]) maxi(dp[i], dp[i + 1] + 1);
            neg++;
            while (b[l] > a[i]) l--;
            while (b[r] - neg > b[l]) r--;
            maxi(dp[i], r - l + 1);
            ansl = max(ansl, dp[i]);
        }
        fore(i,0,n+1) dp[i] = 0;
        ll ansr = 0;
        r = m - 1;
        while (r > 0 && b[r - 1] > 0) r--;
        l = r;
        fore(i,1,n) {
            if (a[i] < 0) continue;
            if (mp[a[i]]) maxi(dp[i], dp[i - 1] + 1);
            pos++;
            while (b[r] < a[i]) r++;
            while (b[r] - pos > b[l]) l++;
            maxi(dp[i], r - l + 1);
            ansr = max(ansr, dp[i]);
        }
        cout << ansl + ansr << '\n';
    }
    return 0;
}