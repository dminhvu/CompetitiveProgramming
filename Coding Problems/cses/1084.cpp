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
    int n, m, k; cin >> n >> m >> k;
    priority_queue<int> a, b;
    rep(i,n) {
        int x; cin >> x;
        a.push(x);
    }
    rep(i,m) {
        int x; cin >> x;
        b.push(x);
    }
    int ans = 0;
    while (a.size() && b.size()) {
        int cur_app = a.top();
        int cur_size = b.top();
        if (cur_size >= cur_app - k && cur_size <= cur_app + k) {
            ans += 1;
            a.pop();
            b.pop();
        } else if (cur_size > cur_app + k) {
            b.pop();
        } else if (cur_size < cur_app - k) {
            a.pop();
        }
    }
    cout << ans;
    return 0;
}