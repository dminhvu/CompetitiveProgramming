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
    freopen("input.txt","r",stdin);
    int m, n;
    double x, y;
    while (cin >> m >> x >> y >> n && m > 0) {
        map<int, double> mp;
        rep(i,n) {
            int t; double r; cin >> t >> r;
            fore(j,t,100) mp[j] = r;
        }
        int ans = 0;
        double curOwe = y, curCarVal = (y + x) * (1.0 - mp[0]);
        double diff = y / m;
        while (curCarVal < curOwe) {
            // cout << curOwe << " " << curCarVal << '\n';
            ans++;
            curOwe -= diff;
            curCarVal = curCarVal * (1.0 - mp[ans]);
        }
        cout << ans << " month";
        if (ans != 1) cout << "s\n";
        else cout << '\n';
    }
    return 0;
}