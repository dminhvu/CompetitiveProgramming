#include<bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<bool> t(n);
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        t[i] = (s[0] == 'A');
    }
    int ans = 0;
    for (int mask = 0; mask < (1 << n); mask++) {
        vector<bool> v(n, 0);
        for (int i = 0; i < n; i++) v[i] = (mask & (1 << i));
        bool cur = v[0];
        for (int i = 1; i < n; i++) {
            if (t[i - 1]) cur &= v[i];
            else cur |= v[i];
        }
        ans += cur;
    }
    cout << ans;
    return 0;
}