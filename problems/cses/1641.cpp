#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < int(n); i++)
#define fore(i,a,b) for (int i = int(a); i <= int(b); i++)
#define ford(i,a,b) for (int i = int(a); i >= int(b); i--)
#define ll int64_t
#define sz(x) int(x.size())

using namespace std;
template<class t, class u> bool maxi(t &a, u b){ if (a < b){ a = b; return 1;} return 0;}
template<class t, class u> bool mini(t &a, u b){ if (a > b){ a = b; return 1;} return 0;}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, x; cin >> n >> x;
    vector<pair<int, int> > a(n);
    rep(i,n) {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a.begin(), a.end());
    int ans_x, ans_y, ans_z = -1;
    rep(i,n) {
        if (ans_z != -1) break;
        int l = 0, r = n - 1;
        while (l < r) {
            if (l < i && i < r && a[l].first + a[i].first + a[r].first == x) {
                ans_x = a[l].second + 1;
                ans_y = a[i].second + 1;
                ans_z = a[r].second + 1;
                break;
            }
            if (a[l].first + a[i].first + a[r].first < x) {
                l += 1;
            } else {
                r -= 1;
            }
        }
    }
    if (ans_z == -1) {
        cout << "IMPOSSIBLE";
    } else {
        cout << ans_x << " " << ans_y << " " << ans_z;
    }
    return 0;
}