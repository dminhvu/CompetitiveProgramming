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
    int n; cin >> n;

    vector<vector<ll> > C(n*n + 1, vector<ll>(2, 0));
    fore(i,1,n*n) {
        C[i][0] = 1;
        C[i][1] = C[i - 1][0] + C[i - 1][1];
        C[i][2] = C[i - 1][1] + C[i - 2][2];
    }
    fore(i,1,n) {
        if (i == 1) cout << 0 << '\n';
        else {
            ll ans = 0;
            ans += C[i*i][2];
            ans -= 4ll * (i - 1) * (i - 2);
            cout << ans << '\n';
        }
    }

    return 0;
}