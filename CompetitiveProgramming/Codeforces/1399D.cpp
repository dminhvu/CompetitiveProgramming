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
        string s; cin >> s;
        vector<set<int> > pos(2);
        rep(i,n) { 
            pos[s[i] - '0'].insert(i + 1);
        }
        int ans = 0;
        vector<int> res(n + 1, 0);
        while (1) {
            if (pos[0].empty() && pos[1].empty()) break;
            if (pos[0].size() && pos[1].size()) {
                ans += 1;
                int f = 0;
                if (*pos[1].begin() < *pos[0].begin()) f = 1;
                vector<int> cur;
                cur.pb(0);
                while (1) {
                    if (f) {
                        if (pos[1].size()) {
                            auto it = pos[1].upper_bound(cur.back());
                            if (it != pos[1].end()) {
                                res[*it] = ans;
                                cur.pb(*it);
                                pos[1].erase(it);
                            } else {
                                break;
                            }
                        } else {
                            break;
                        }
                    } else {
                        if (pos[0].size()) {
                            auto it = pos[0].upper_bound(cur.back());
                            if (it != pos[0].end()) {
                                res[*it] = ans;
                                cur.pb(*it);
                                pos[0].erase(it);
                            } else {
                                break;
                            }
                        } else {
                            break;
                        }
                    }
                    f ^= 1;
                }
            } else {
                rep(i,2) {
                    for(int x: pos[i]) res[x] = ++ans;
                }
                break;
            }
        }
        cout << ans << '\n';
        rep(i,n) cout << res[i + 1] << " ";
        cout << '\n';
    }
    return 0;
}