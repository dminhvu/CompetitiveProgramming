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
        int n, m; cin >> n >> m;
        vector<set<int> > dayOf(n), day(m);
        rep(i,m) {
            int k; cin >> k;
            rep(j,k) {
                int x; cin >> x;
                dayOf[x - 1].insert(i);
                day[i].insert(x - 1);
            }
        }
        bool f = 1;
        rep(i,n) {
            if (dayOf[i].empty()) continue;
            int cnt = sz(dayOf[i]);
            for(auto it = dayOf[i].begin(); it != dayOf[i].end(); it++) {
                if (cnt <= (m + 1) / 2) break;
                if (sz(day[*it]) > 1) {
                    day[*it].erase(i);
                    --cnt;
                }
            }
            if (cnt > (m + 1) / 2) {
                f = 0;
                break;
            }
        }
        rep(i,m) if (sz(day[i]) == 0) {
            f = 0;
            break;
        }
        if (!f) {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
        rep(i,m) {
            cout << *day[i].begin() + 1 << ' ';
        }
        cout << '\n';
    }
    return 0;
}