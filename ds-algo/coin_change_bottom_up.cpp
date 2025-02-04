#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < int(n); i++)
#define fore(i,a,b) for (int i = int(a); i <= int(b); i++)
#define ford(i,a,b) for (int i = int(a); i >= int(b); i--)
#define ll int64_t
#define sz(x) int(x.size())

using namespace std;
template<class t, class u> bool maxi(t &a, u b){ if (a < b){ a = b; return 1;} return 0;}
template<class t, class u> bool mini(t &a, u b){ if (a > b){ a = b; return 1;} return 0;}

const int inf = 1e9;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n = 4, V = 12;
    vector<int> coin = {1, 3, 4, 5};
    vector<int> dp(V + 1, inf); // dp[i] = minimum coin needed to get total value of coins equals i
    dp[0] = 0;
    fore(i,1,V) {
        rep(j,n) {
            if (i < coin[j]) continue;
            dp[i] = min(dp[i], dp[i - coin[j]] + 1);
        }
    }
    cout << dp[V] << '\n';
    return 0;
}