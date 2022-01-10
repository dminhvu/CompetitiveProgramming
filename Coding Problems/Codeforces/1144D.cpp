#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < int(n); i++)
#define fore(i,a,b) for (int i = int(a); i <= int(b); i++)
#define ford(i,a,b) for (int i = int(a); i >= int(b); i--)
#define ll int64_t
#define sz(x) int(x.size())

using namespace std;
template<class t, class u> bool maxi(t &a, u b){ if (a < b){ a = b; return 1;} return 0;}
template<class t, class u> bool mini(t &a, u b){ if (a > b){ a = b; return 1;} return 0;}

const int inf = 1e9 + 5;
const int N = 2e5 + 5;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    vector<int> cnt(N, 0);
    rep(i,n) cnt[a[i]] += 1;
    int most_freq_element = 0, count = 0;
    rep(i,n) {
        if (cnt[a[i]] > count) {
            count = cnt[a[i]];
            most_freq_element = a[i];
        }
    }
    queue<int> q;
    rep(i,n) {
        if (a[i] == most_freq_element) {
            q.push(i);
        }
    }
    vector<tuple<int, int, int> > ans;
    while (q.size()) {
        int u = q.front();
        q.pop();
        if (u > 0 && a[u - 1] != a[u]) {
            if (a[u - 1] > a[u]) {
                ans.push_back({2, u - 1, u});
            } else {
                ans.push_back({1, u - 1, u});
            }
            a[u - 1] = a[u];
            q.push(u - 1);
        }
        if (u < n - 1 && a[u + 1] != a[u]) {
            if (a[u + 1] > a[u]) {
                ans.push_back({2, u + 1, u});
            } else {
                ans.push_back({1, u + 1, u});
            }
            a[u + 1] = a[u];
            q.push(u + 1);
        }
    }
    cout << ans.size() << '\n';
    for (int i = 0; i < ans.size(); i++) {
        cout << get<0>(ans[i]) << " " << get<1>(ans[i]) + 1 << " " << get<2>(ans[i]) + 1 << '\n';
    }
    return 0;
}