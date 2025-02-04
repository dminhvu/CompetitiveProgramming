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
    // freopen64("input.txt","r",stdin);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<int> a(n + 1), b(n + 1), pos(n + 2, 0);
    rep(i,n) cin >> a[i + 1];
    rep(i,n) {
        cin >> b[i + 1];
        pos[b[i + 1]] = i + 1;
    }
    if (pos[1]) {
        int p = pos[1];
        int cnt = 1;
        for(int i = pos[1]; i <= n; i++) {
            if (pos[cnt] == i) {
                cnt++;
                p = i;
            } else {
                break;
            }
        }
        if (p == n) {
            for(int i = 0; i <= n && cnt <= n; i++) {
                if (pos[cnt] <= i) {
                    ++cnt;
                } else {
                    break;
                }
            }
            if (cnt > n) {
                cout << pos[1] - 1 << '\n';
                return 0;
            }
        }
    }
    int ans = 0;
    fore(i,1,n) {
        ans = max(ans, pos[i] - i + 1 + n);
    }
    cout << ans << '\n';
    return 0;
}