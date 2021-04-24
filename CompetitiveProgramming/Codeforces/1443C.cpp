#include<bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int nTest; cin >> nTest;
    while (nTest--) {
        int n; cin >> n;
        vector<int64_t> a(n), b(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];
        int64_t l = 0, r = 1e18;
        while (l <= r) {
            int64_t mid = (l + r) >> 1ll;
            int64_t res = 0, sum = 0;
            for (int i = 0; i < n; i++) {
                if (mid >= a[i]) res = max(res, a[i]);
                else {
                    sum += b[i];
                    res = max(res, sum);
                }
            }
            if (res <= mid) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        cout << l << '\n';
    }
    return 0;
}