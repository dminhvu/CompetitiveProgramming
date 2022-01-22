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
    int n; cin >> n;
    vector<tuple<int, int, int> > a;
    rep(i,n) {
        int x, y; cin >> x >> y;
        a.push_back({x, 0, i});
        a.push_back({y, 1, i});
    }
    sort(a.begin(), a.end());
    vector<int> ans(n);
    vector<int> prev;
    int cnt = 0;
    for (auto [x, t, i]: a) {
        if (t == 0) {
            cnt += 1;
            if (prev.empty()) {
                ans[i] = cnt;
            } else {
                ans[i] = prev.back();
                prev.pop_back();
            }
        } else {
            cnt -= 1;
            prev.push_back(ans[i]);
        }
    }
    cout << *max_element(ans.begin(), ans.end()) << '\n';
    rep(i,n) cout << ans[i] << " ";
    return 0;
}