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
    int n, l; cin >> n >> l;
    set<int> s;
    rep(i,n) {
        int x; cin >> x;
        s.insert(x);
    }
    double ans = 0;
    for(auto it = s.begin(); it != s.end(); it++) {
        if (it == s.begin()) continue;
        auto it2 = it;
        --it2;
        maxi(ans, (*it - *it2) / 2.0);
    }
    if (*s.begin() != 0) maxi(ans, *s.begin());
    if (*(--s.end()) != l) maxi(ans, l - *(--s.end()));
    cout << ans;
    return 0;
}