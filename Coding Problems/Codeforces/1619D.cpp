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
        int m, n; cin >> m >> n;
        vector<vector<int> > a(m, vector<int>(n, 0));
        rep(i,m) {
            rep(j,n) cin >> a[i][j];
        }
        int l = 0, r = 1e9;
        while (l <= r) {
            int mid = (l + r) >> 1;
            bool valid = true;
            vector<bool> shopped(m, false);
            bool shop = false;
            int buyers = 0;
            rep(j,n) {
                bool bought = false;
                rep(i,m) {
                    if (a[i][j] >= mid) {
                        bought = true;
                        if (shopped[i]) shop = true;
                        shopped[i] = true;
                    }
                }
                if (bought) buyers += 1;
            }
            if (buyers == n && shop) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        cout << r << '\n';
    }
    return 0;
}