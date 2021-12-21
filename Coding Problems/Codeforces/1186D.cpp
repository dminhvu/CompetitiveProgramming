#include<bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<int> a(n);
    vector<bool> f(n, false);
    for(int i=0; i<n; i++) {
        double x; cin >> x;
        if (floor(x)==x) f[i] = true;
        a[i] = int(floor(x));
    }
    int64_t sum = accumulate(a.begin(), a.end(), 0ll);
    for(int i=0; i<n; i++) {
        if (f[i]) continue;
        if (sum == 0) break;
        a[i] += 1;
        sum += 1;
    }
    for(int i=0; i<n; i++) cout << a[i] << '\n';
    return 0;
}