#include<bits/stdc++.h>

using namespace std;
const int64_t inf = 1e18;
const int N = 1e6;

bool mini(int64_t &a, int64_t b) {
    if (a > b) {
        a = b;
        return 1;
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("input.txt","r",stdin);
    int nTest; cin >> nTest;
    while (nTest--) {
        int n; int64_t u, v; cin >> n >> u >> v;
        vector<int64_t> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        int64_t ans = inf;
        for (int i = 1; i < n; i++) {
            if (abs(a[i] - a[i - 1]) <= 1) {
                if (abs(a[i] - a[i - 1]) == 1) {
                    if (a[i] != N) {
                        mini(ans, u);
                        mini(ans, v);
                    } else {
                        mini(ans, u);
                    }
                } else {
                    mini(ans, u + v);
                    mini(ans, v + v);
                }
            } else ans = 0;
        }
        cout << ans << '\n';
    }
    return 0;
}