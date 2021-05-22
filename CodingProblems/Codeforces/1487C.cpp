#include<bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("input.txt","r",stdin);
    int nTest; cin >> nTest;
    while (nTest--) {
        int n; cin >> n;
        if (n & 1) {
            int x = 1;
            int mx = n - 1, cnt = 0;
            for (int i = 0; i < (n * (n - 1)) / 2; i++) {
                cout << x << " ";
                cnt++;
                if (cnt == mx) {
                    mx--;
                    cnt = 0;
                    x = 1;
                    continue;
                }
                if (x == 1) x = -1;
                else x = 1;
            }
        } else {
            for (int i = 0; i < n; i++) {
                if (i % 2 == 0) cout << 0 << " ";
                for (int j = i + 1 + (i % 2 == 0); j < n; j++) {
                    if (j % 2 == 0) cout << -1 << " ";
                    else cout << 1 << " ";
                }
            }
        }
        cout << '\n';
    }
    return 0;
}