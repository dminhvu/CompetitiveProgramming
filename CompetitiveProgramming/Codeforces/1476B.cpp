#include<bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int nTest; cin >> nTest;
    while (nTest--) {
        int n, k; cin >> n >> k;
        vector<int> a(n), f(n, 0);
        int ans = 0;
        for (int i = 0; i < n; i++) cin >> a[i];
        f[0] = a[0];
        for (int i = 1; i < n; i++) {
            f[i] = f[i - 1];
            if (a[i] * 100  > f[i - 1] * k) {
                int t = (a[i] * 100) / k;
                t += ((a[i] * 100) % k != 0);
                int newa = a[i - 1] * t;
                f[i] += newa - a[i - 1];
                ans += newa - a[i - 1];
                a[i - 1] = newa;
                cout << newa - a[i - 1] << ' ';
            }
            f[i] += a[i];
        }
        cout << ans << '\n';
    }
    return 0;
}