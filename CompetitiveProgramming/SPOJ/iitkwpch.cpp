#include<bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int nTest; cin >> nTest;
    while (nTest--) {
        int n; cin >> n;
        set<int> s[10];
        int64_t ans = 0;
        for (int i = 0; i < n; i++) {
            int64_t x; cin >> x;
            set<int> curset;
            int64_t y = x;
            while (x) {
                int r = x % 10ll;
                x /= 10ll;
                curset.insert(s[r].begin(), s[r].end());
            }
            x = y;
            while (x) {
                int r = x % 10ll;
                x /= 10ll;
                s[r].insert(i);
            }
            ans += 1ll * int(curset.size());
        }
        cout << ans << '\n';
    }
    return 0;
}