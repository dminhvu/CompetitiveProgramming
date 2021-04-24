#include<bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("input.txt","r",stdin);
    int a, b, k; cin >> a >> b >> k;
    vector<int> x(200005, 0), y(200005, 0), z(200005, 0);
    for (int i = 0; i < k; i++) z[i] = 1;
    if (k > 0) y[0] = 1;
    // for (int i = 1; i < )
    int cnt = b - (k > 0);
    for (int i = a + b - 1; cnt; i--) {
        --cnt;
        if (i == k) {
            for (int j = 1; j < i; j++) y[j] = 1;
            break;
        }
        y[i] = x[i] = 1;
    }
    int r = 0;
    for (int i = 0; i < a + b; i++) {
        x[i] = r + y[i] + z[i];
        if (x[i] > 1) {
            r = 1;
            x[i] %= 2;
        } else r = 0;
    }
    int cnt1 = 0, cnt0 = 0;
    for (int i = 0; i < a + b; i++) {
        cnt1 += x[i] == 1;
        cnt0 += x[i] == 0;
    }
    if (cnt1 != b && cnt0 != a) {
        cout << "No\n";
        return 0;
    }
    cnt1 = 0, cnt0 = 0;
    for (int i = 0; i < a + b; i++) {
        cnt1 += y[i] == 1;
        cnt0 += y[i] == 0;
    }
    if (cnt1 != b && cnt0 != a) {
        cout << "No\n";
        return 0;
    }
    cnt1 = 0, cnt0 = 0;
    for (int i = 0; i < a + b; i++) {
        cnt1 += z[i] == 1;
    }
    if (cnt1 != k) {
        cout << "No\n";
        return 0;
    }
    cout << "Yes\n";
    for (int i = a + b - 1; i >= 0; i--) cout << x[i];
    cout << '\n';
    for (int i = a + b - 1; i >= 0; i--) cout << y[i];
    cout << '\n';
    // for (int i = a + b - 1; i >= 0; i--) cout << z[i];
    return 0;
}