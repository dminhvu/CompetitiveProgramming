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
    vector<ll> upper, max_nines;
    upper.push_back(0);
    ll max_num = 0;
    fore(i,1,100) {
        max_nines.push_back(max_num);
        if (upper.back() > ll(1e18)) break;
        ll next_max_num = max_num * 10ll + 9;
        upper.push_back(upper.back() + 1ll * i * (next_max_num - max_num));
        max_num = next_max_num;
    }
    int T; cin >> T;
    while (T--) {
        ll k; cin >> k;
        int len = 0;
        rep(i,upper.size()) {
            if (k > upper[i]) {
                len = i + 1;
            }
        }
        ll num = (k - upper[len - 1] + 1ll * len - 1ll) / (1ll * len) + max_nines[len - 1];
        ll k_left = (upper[len - 1] + 1ll * len * (num - max_nines[len - 1])) % k;
        vector<int> digit;
        while (num) {
            digit.push_back(num % 10ll);
            num /= 10ll;
        }
        cout << digit[k_left] << '\n';
    }
    return 0;
}