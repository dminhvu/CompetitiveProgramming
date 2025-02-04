#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < int(n); i++)
#define fore(i,a,b) for (int i = int(a); i <= int(b); i++)
#define ford(i,a,b) for (int i = int(a); i >= int(b); i--)
#define ll int64_t
#define sz(x) int(x.size())

using namespace std;
template<class t, class u> bool maxi(t &a, u b){ if (a < b){ a = b; return 1;} return 0;}
template<class t, class u> bool mini(t &a, u b){ if (a > b){ a = b; return 1;} return 0;}

struct segment {
    int length, x, y;
    
};

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int x, n; cin >> x >> n;
    set<pair<int, int> > s;
    multiset<int> ms;
    s.insert({0, x});
    ms.insert(x);
    rep(i,n) {
        int y; cin >> y;
        auto it = s.upper_bound({y, y});
        --it;
        int len = it->second - it->first;
        s.insert({it->first, y});
        ms.insert(y - it->first);
        s.insert({y, it->second});
        ms.insert(it->second - y);
        s.erase(it);
        auto it2 = ms.find(len);
        ms.erase(it2);
        cout << *(--ms.end()) << ' ';
    }
    return 0;
}