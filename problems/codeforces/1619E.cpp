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
    // freopen("input.txt","r",stdin);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int nTest; cin >> nTest;
    while (nTest--) {
        int n; cin >> n;
        vector<int> a(n);
        rep(i,n) cin >> a[i];
        stack<pair<int, int> > st;
        vector<ll> cnt(n + 1, 0);
        rep(i,n) cnt[a[i]] += 1;
        bool invalid = false;
        ll cummulative = 0;
        rep(i,n+1) {
            if (invalid) {
                cout << -1 << " ";
            } else if (i == 0) {
                cout << cnt[0] << " ";
                if (cnt[0] > 1) {
                    st.push({0, cnt[0] - 1});
                }
            } else {
                if (cnt[i - 1] == 0) {
                    if (st.empty()) {
                        invalid = true;
                        cout << -1 << " ";
                        continue;
                    }
                    int ans = i - 1 - st.top().first;
                    st.top().second -= 1;
                    if (st.top().second == 0) st.pop();
                    cummulative += ans;
                }
                cout << cummulative + cnt[i] << " ";
                if (cnt[i] > 1) {
                    st.push({i, cnt[i] - 1});
                }
            }
        }
        cout << '\n';
    }
    return 0;
}