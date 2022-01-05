#include<bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    vector<vector<int> > a(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            if (j > 0) a[i][j] += a[i][j - 1]; // prefix sum for i-th row
        }
    }
    int ans = 0;
    for (int i = 0; i < m; i++) { // fix i
        for (int j = i + 1; j < m; j++) { // fix j
            int sum = 0;
            for (int k = 0; k < n; k++) { // iterate from first row
                sum += a[k][j];
                if (i > 0) sum -= a[k][i - 1];
                ans = max(ans, sum);
                if (sum < 0) sum = 0;
            }
        }
    }
    cout << ans;
    return 0;
}