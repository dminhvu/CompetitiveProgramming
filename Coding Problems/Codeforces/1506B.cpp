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
const int inf = 1e9;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("input.txt","r",stdin);
    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        string s; cin >> s;
        s = ' ' + s;
        int ans = 0;
        int l = -1;
        vector<int> pos;
        fore(i,1,n) if (s[i] == '*') pos.pb(i);
        vector<int> dp(n + 1, inf);
        fore(i,1,n) {
            if (s[i] == '*') {
                dp[i] = 1;
                break;
            }
        }
        fore(i,1,n) {
            fore(j,i+1,n) {
                if (j - i <= k && s[j] == '*') mini(dp[j], dp[i] + 1);
            }
            // if (i + k <= n && s[i + k] == '*') mini(dp[i + k], dp[i] + 1);
        }
        int r = -1;
        ford(i,n,1) {
            if (s[i] == '*') {
                r = i;
                break;
            }
        }
        cout << dp[r] << '\n';
    }
    return 0;
}