#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < int(n); i++)
#define fore(i,a,b) for (int i = int(a); i <= int(b); i++)
#define ford(i,a,b) for (int i = int(a); i >= int(b); i--)
#define ll int64_t
#define sz(x) int(x.size())

using namespace std;
template<class t, class u> bool maxi(t &a, u b){ if (a < b){ a = b; return 1;} return 0;}
template<class t, class u> bool mini(t &a, u b){ if (a > b){ a = b; return 1;} return 0;}

const int inf = 1e9 + 7;

int main() {
    // freopen("input.txt","r",stdin);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int nTest; cin >> nTest;
    while (nTest--) {
        ll n; cin >> n;
        int ans = inf;
        vector<ll> fact;
        ll num = 1, cnt = 2;
        while (num <= n) {
            fact.push_back(num);
            num *= cnt;
            cnt += 1;
        }
        int k = fact.size();
        vector<ll> factsum((1 << k), 0ll);
        for (int i = 0; i < (1 << k); i++) {
            int curans = 0;
            ll m = n;
            for (int j = 0; j < k; j++) {
                if ((i >> j) & 1) {
                    m -= fact[j];
                    curans += 1;
                }
            }
            mini(ans, curans + __builtin_popcountll(m));
        }
        cout << ans << '\n';
    }
    return 0;
}