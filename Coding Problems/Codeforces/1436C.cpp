#include<bits/stdc++.h>

using namespace std;
const int64_t mod = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("input.txt","r",stdin);
    int n, x, pos; cin >> n >> x >> pos;
    vector<int64_t> f(n + 1, 1);
    for (int i = 1; i <= n; i++) {
        f[i] = (f[i - 1] % mod * i) % mod;
    }
    vector<vector<int64_t> > C(n + 1, vector<int64_t>(n + 1, 0));
    for (int i = 1; i <= n; i++) C[1][i] = i;
    for (int i = 0; i <= n; i++) {
        C[i][i] = 1;
        C[0][i] = 1;
    }
    for (int i = 2; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            C[i][j] = (C[i - 1][j - 1] % mod + C[i][j - 1] % mod) % mod;
        }
    }
    cout << C[n - pos][n - x] << '\n';
    cout << (C[n - pos][n - x] % mod * f[pos] % mod) % mod;
    return 0;
}