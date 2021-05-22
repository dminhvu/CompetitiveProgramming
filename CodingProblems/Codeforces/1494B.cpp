#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
#define fore(i,a,b) for (int i = (a); i <= (b); i++)
#define ford(i,a,b) for (int i = (a); i >= (b); i--)
#define ll int64_t
#define pb push_back
#define fi first
#define se second
#define sz(x) int(x.size())

using namespace std;
template<class t, class u> bool maxi(t &a, u b){ if (a < b){ a = b; return 1;} return 0;}
template<class t, class u> bool mini(t &a, u b){ if (a > b){ a = b; return 1;} return 0;}

int n;

bool check(int u, int d, int l, int r) {
    if (u == n) l--, r--;
    if (d == n) l--, r--;
    if (u == n - 1) if (l) l--; else r--;
    if (d == n - 1) if (l) l--; else r--;
    return (u >= 0 && d >= 0 && l >= 0 && r >= 0);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--) {
        int u, r, d, l; cin >> n >> u >> r >> d >> l;
        if (check(u, d, l, r) && check(l, r, u, d)) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}