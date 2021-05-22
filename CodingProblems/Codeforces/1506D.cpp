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
        int n; cin >> n;
        map<int, int> mp;
        rep(i,n) {
            int x; cin >> x;
            mp[x]++;
        }
        multiset<int> ms;
        for(auto [x, y]: mp) ms.insert(y);
        while (ms.size() > 1) {
            auto it = ms.begin();
            auto it2 = --ms.end();
            if (*it > 1) ms.insert(*it - 1);
            if (*it2 > 1) ms.insert(*it2 - 1);
            ms.erase(it);
            ms.erase(it2);
        }
        if (ms.empty()) cout << 0 << '\n';
        else cout << *ms.begin() << '\n';
    }
    return 0;
}