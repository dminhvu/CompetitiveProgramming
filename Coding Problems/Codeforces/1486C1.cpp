#include<bits/stdc++.h>
 
using namespace std;
 
int ask(int l, int r) {
    if (l >= r) return -1;
    cout << "? " << l << " " << r << '\n';
    cout.flush();
    int ans; cin >> ans;
    return ans;
}
 
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    int l = 1, r = n;
    while (l + 1 < r) {
        int mid = (l + r) >> 1;
        int id = ask(l, r);
        if (id < mid) {
            if (ask(l, mid - 1) == id) {
                r = mid;
            } else {
                l = mid;
            }
        } else {
            if (ask(mid, r) == id) {
                l = mid;
            } else {
                r = mid;
            }
        }
    }
    cout << "! " << r - 1 << '\n';
    return 0;
}