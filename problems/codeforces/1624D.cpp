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
    int T; cin >> T;
    while (T--) {
        int n, k; cin >> n >> k;
        string s; cin >> s;
        vector<int> cnt(26, 0);
        for (char c: s) cnt[c - 'a'] += 1;
        int count_pairs = 0, count_odd = 0;
        rep(i,26) {
            count_pairs += cnt[i] / 2;
            count_odd += cnt[i] % 2;
        }
        int ans = 2 * (count_pairs / k);
        count_odd += 2 * (count_pairs % k);
        if (count_odd >= k) {
            ans += 1;
        }
        cout << ans << '\n';
    }
    return 0;
}