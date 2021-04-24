#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < int(n); i++)
#define fore(i,a,b) for (int i = int(a); i <= int(b); i++)
#define ford(i,a,b) for (int i = int(a); i >= int(b); i--)
#define ll int64_t
#define pb push_back
#define fi first
#define se second
#define sz(x) int(x.size())

using namespace std;
template<class t, class u> bool maxi(t &a, u b){ if (a < b){ a = b; return 1;} return 0;}
template<class t, class u> bool mini(t &a, u b){ if (a > b){ a = b; return 1;} return 0;}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--) {
        int n, x; cin >> n >> x;
        vector<int> cnt(2, 0);
        rep(i,n) {
            int y; cin >> y;
            cnt[y % 2]++;
        }
        if (cnt[1] == 0) {
            cout << "No\n";
            continue;
        }
        x--;
        cnt[1]--;
        while (cnt[1] >= 2 && x >= 2) {
            x -= 2;
            cnt[1] -= 2;
        }
        while (cnt[0] && x > 0) {
            x--;
            cnt[0]--;
        }
        cout << (x == 0 ? "Yes\n" : "No\n");
    }
    
    return 0;
}