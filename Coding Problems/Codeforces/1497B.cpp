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
        int n, m; cin >> n >> m;
        vector<int> cnt(m, 0);
        rep(i,n) {
            int x; cin >> x;
            x %= m;
            cnt[x]++;
        }
        int ans = (cnt[0] > 0);
        fore(i,1,m/2) {
            if (i * 2 == m) {
                ans += (cnt[i] > 0);
                continue;
            }
            int minCnt = min(cnt[i], cnt[m - i]);
            ans += (minCnt > 0);
            cnt[i] -= minCnt;
            cnt[m - i] -= minCnt;
            if (minCnt > 0 && cnt[i] > 0) cnt[i]--;
            else if (minCnt > 0 && cnt[m - i] > 0) cnt[m - i]--;
            ans += cnt[i] + cnt[m - i];
            // cout << ans << " ";
        }
        cout << ans << '\n';
    }
    return 0;
}