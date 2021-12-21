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
        vector<int> a(n);
        rep(i,n) cin >> a[i];
        int max_val = 0, max_pos = 0;
        int min_val = 1e3, min_pos = 0;
        rep(i,n) {
            if (maxi(max_val, a[i])) {
                max_pos = i;
            }
            if (mini(min_val, a[i])) {
                min_pos = i;
            }
        }
        int x = min_pos;
        int y = max_pos;
        cout << min({x + 1 + n - y, max(x + 1, y + 1), max(n - x, n - y), y + 1 + n - x}) << '\n';
    }
    return 0;
}