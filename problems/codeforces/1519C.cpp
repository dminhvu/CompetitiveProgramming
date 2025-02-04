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
    int nTest; cin >> nTest;
    while (nTest--) {
        int n, k; cin >> n >> k;
        multiset<pair<int, int> > ms;
        vector<int> neg, pos;
        rep(i,n) {
            int x; cin >> x;
            ms.insert({abs(x), x});
            if (x < 0) neg.push_back(x);
            else pos.push_back(x);
        }
        sort(neg.begin(), neg.end(), greater<int>());
        sort(pos.begin(), pos.end());
        bool furthest = true;
        ll ans = 0;
        while (ms.size()) {
            int cnt = k;
            auto it = ms.rbegin();
            int sign = (it->second >= 0);
            if (furthest) {
                ans += it->first;
                furthest = false;
            } else {
                ans += 2ll * it->first;
            }
            ms.erase(--ms.end());
            if (sign) pos.pop_back();
            else neg.pop_back();
            cnt -= 1;
            if (sign) {
                while (ms.size() && pos.size() && cnt--) {
                    auto it2 = ms.find({pos.back(), pos.back()});
                    ms.erase(it2);
                    pos.pop_back();
                }
            } else {
                while (ms.size() && neg.size() && cnt--) {
                    auto it2 = ms.find({abs(neg.back()), neg.back()});
                    ms.erase(it2);
                    neg.pop_back();
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}