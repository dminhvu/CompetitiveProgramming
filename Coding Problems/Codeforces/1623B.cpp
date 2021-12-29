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
        int n; cin >> n;
        set<pair<int, int> > s;
        rep(i,n) {
            int u, v; cin >> u >> v;
            s.insert({u, v});
        }
        queue<pair<int, int> > q;
        q.push({1, n});
        set<pair<pair<int, int>, int> > ans;
        while (q.size()) {
            int l = q.front().first;
            int r = q.front().second;
            q.pop();
            s.erase({l, r});
            if (l == r) {
                ans.insert({{l, r}, r});
                continue;
            }
            for (int i = l; i <= r; i++) {
                if (i == l && s.find({i + 1, r}) != s.end()) {
                    q.push({i + 1, r});
                    ans.insert({{l, r}, i});
                }
                if (i == r && s.find({l, i - 1}) != s.end()) {
                    q.push({l, i - 1});
                    ans.insert({{l, r}, i});
                }
                if (i > l && i < r && s.find({l, i - 1}) != s.end() && s.find({i + 1, r}) != s.end()) {
                    q.push({i + 1, r});
                    q.push({l, i - 1});
                    ans.insert({{l, r}, i});
                }
            }
        }
        for (auto it: ans) cout << it.first.first << " " << it.first.second << " " << it.second << '\n';
        cout << '\n';
    }
    return 0;
}