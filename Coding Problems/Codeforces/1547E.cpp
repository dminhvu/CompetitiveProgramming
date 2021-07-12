#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < int(n); i++)
#define fore(i,a,b) for (int i = int(a); i <= int(b); i++)
#define ford(i,a,b) for (int i = int(a); i >= int(b); i--)
#define ll int64_t
#define sz(x) int(x.size())

using namespace std;
template<class t, class u> bool maxi(t &a, u b){ if (a < b){ a = b; return 1;} return 0;}
template<class t, class u> bool mini(t &a, u b){ if (a > b){ a = b; return 1;} return 0;}
const int N = 3e5 + 5;
const int inf = 2e9;

int main() {
    freopen64("input.txt","r",stdin);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int nTest; cin >> nTest;
    while (nTest--) {
        int n, k; cin >> n >> k;
        vector<pair<ll, ll> > a(k);
        rep(i,k) cin >> a[i].first;
        rep(i,k) cin >> a[i].second;
        sort(a.begin(), a.end());
        vector<ll> ans(n + 2, inf);
        int id = 0;
        fore(i,1,n) {
            while (id < k - 1 && abs(i - a[id].first) + a[id].second > abs(i - a[id + 1].first) + a[id + 1].second) {
                id++;
            }
            ans[i] = min(ans[i], abs(i - a[id].first) + a[id].second);
        }
        id = k - 1;
        ford(i,n,1) {
            while (id > 0 && abs(i - a[id].first) + a[id].second > abs(i - a[id - 1].first) + a[id - 1].second) {
                id--;
            }
            ans[i] = min(ans[i], abs(i - a[id].first) + a[id].second);
        }
        fore(i,1,n) cout << ans[i] << " ";
        cout << '\n';
    }
    return 0;
}