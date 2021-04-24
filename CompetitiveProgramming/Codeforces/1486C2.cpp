#include<bits/stdc++.h>

using namespace std;

bool f = 0;

int query(int l, int r) {
    // if (l >= r) return -1;
    cout << "? " << l << " " << r << '\n';
    cout.flush();
    int id; cin >> id;
    return id;
}

int main() {
    // ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, ans; cin >> n;
    int second_max = query(1, n);
    if(second_max > 1 && query(1, second_max) == second_max) {
        int l = 1, r = second_max-1, mid;
        while (l <= r) {
            mid = (l + r) >> 1;
            if(query(mid, second_max) == second_max) {
                ans = mid;
                l = mid + 1;
            } else r = mid - 1;
        }
    } else {
        int l = second_max + 1, r = n, mid;
        while (l <= r) {
            mid = (l + r) >> 1;
            if(query(second_max, mid) == second_max) {
                ans = mid;
                r = mid-1;
            } else l = mid+1;
        }
    }
    cout << "! " << ans << endl;
    cout.flush();
    return 0;
}