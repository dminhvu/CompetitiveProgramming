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
    int n, m; cin >> n >> m;
    multiset<int> ms;
    rep(i,n) {
        int x; cin >> x;
        ms.insert(x);
    }
    rep(i,m) {
        int x; cin >> x;
        auto it = ms.lower_bound(x);
        if (it != ms.end()) {
            if (*it == x) {
                cout << *it << '\n';
                ms.erase(it);
            } else if (it != ms.begin()) {
                --it;
                cout << *it << '\n';
                ms.erase(it);
            } else {
                cout << -1 << '\n';
            }
        } else {
            
            if (ms.empty()) {
                cout << -1 << '\n';
            } else {
                --it;
                cout << *it << '\n';
                ms.erase(it);
            }
        }
    }
    return 0;
}