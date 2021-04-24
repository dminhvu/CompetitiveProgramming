#include<bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int nTest; cin >> nTest;
    while (nTest--) {
        int n; cin >> n;
        vector<int64_t> a(n);
        for(int i=0; i<n; i++) cin >> a[i];
        sort(a.begin(), a.end());
        int64_t res = abs(a[n - 1] - a[0]);
        for(int i=1; i<n-1; i++) {
            res = max(res, abs(a[0] - a[n - 1]) + abs(a[0] - a[i]) + abs(a[i] - a[n - 1]));
        }
        cout << res << '\n';
    }
    return 0;
}