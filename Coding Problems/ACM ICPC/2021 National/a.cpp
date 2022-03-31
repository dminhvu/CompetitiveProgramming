#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < int(n); i++)
#define fore(i,a,b) for (int i = int(a); i <= int(b); i++)
#define ford(i,a,b) for (int i = int(a); i >= int(b); i--)
#define ll int64_t
#define sz(x) int(x.size())

using namespace std;
template<class t, class u> bool maxi(t &a, u b){ if (a < b){ a = b; return 1;} return 0;}
template<class t, class u> bool mini(t &a, u b){ if (a > b){ a = b; return 1;} return 0;}

struct ele {
    int first, second;
    bool operator < (const ele &oth) const {
        return second < oth.second;
    }
};

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // freopen("input.txt","r",stdin);
    int n; cin >> n;
    int m = n;
    n = n * n;
    vector<int> a(n + 5);
    rep(i,n) cin >> a[i];
    multiset<ele> ms;
    vector<int> cnt(m + 5, 0);
    rep(i,n) {
        cnt[a[i]] += 1;
    }
    fore(i,1,m+1) {
        if (cnt[i] != 0) {
            ms.insert({i, cnt[i]});
            // cout << i << " " << cnt[i] << '\n';
        }
    }
    vector<pair<int, int> > x, y;
    fore(i,1,m) {
        if (ms.empty()) break;
        if (ms.begin()->second >= m) {
            x.push_back({ms.begin()->first, m});
            y.push_back({0, 0});
            ele tmp = {ms.begin()->first, ms.begin()->second - m};
            ms.erase(ms.begin());
            if (tmp.second > 0) {
                ms.insert(tmp);
            }
        } else {
            x.push_back({ms.begin()->first, ms.begin()->second});
            y.push_back({(--ms.end())->first, m - ms.begin()->second});
            ele tmp = {(--ms.end())->first, (--ms.end())->second - (m - ms.begin()->second)};
            ms.erase(ms.begin());
            if (ms.size()) ms.erase((--ms.end()));
            if (tmp.second > 0) {
                ms.insert(tmp);
            }
        }
    }
    // rep(i,x.size()) cout << x[i].first << " " << x[i].second << " " << y[i].first << " " << y[i].second << '\n';
    vector<int> ans(n + 5, -1);
    rep(i,n) {
        rep(j,x.size()) {
            if (a[i] == x[j].first && x[j].second > 0) {
                ans[i] = j;
                x[j].second -= 1;
                break;
            } else if (a[i] == y[j].first && y[j].second > 0) {
                ans[i] = j;
                y[j].second -= 1;
                break;
            }
        }
        if (ans[i] == -1) {
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
    rep(i,n) cout << ans[i] + 1 << " ";
    return 0;
}