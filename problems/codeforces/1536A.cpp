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
    // freopen64("input.txt","r",stdin);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int nTest; cin >> nTest;
    while (nTest--) {
        int n; cin >> n;
        multiset<int> s;
        rep(i,n) {
            int foo; cin >> foo;
            s.insert(foo);
        }
        if (*s.begin() < 0) {
            cout << "NO\n";
            continue;
        }
        while (1) {
            vector<int> v;
            for(auto it = s.begin(); it != s.end(); it++) {
                v.push_back(*it);
            }
            bool f = 0;
            rep(i,sz(v)) {
                rep(j,sz(v)) {
                    if (i == j) continue;
                    int diff = abs(v[i] - v[j]);
                    int cnt = s.count(diff);
                    if (cnt <= 0) {
                        f = 1;
                        s.insert(diff);
                    }
                }
            }
            if (!f) break;
        }
        cout << "YES\n";
        cout << sz(s) << '\n';
        for(auto it = s.begin(); it != s.end(); it++) cout << *it << " ";
        cout << '\n';
    }
    return 0;
}