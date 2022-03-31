#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < int(n); i++)
#define fore(i,a,b) for (int i = int(a); i <= int(b); i++)
#define ford(i,a,b) for (int i = int(a); i >= int(b); i--)
#define ll int64_t
#define sz(x) int(x.size())

using namespace std;
template<class t, class u> bool maxi(t &a, u b){ if (a < b){ a = b; return 1;} return 0;}
template<class t, class u> bool mini(t &a, u b){ if (a > b){ a = b; return 1;} return 0;}

int transform(char a, char b) {
    int tmp = max(a, b) - min(a, b);
    return min(tmp, 26 - tmp);
}

int calc(char a, char b, char c, char d, char e) {
    return transform(a, e) + transform(b, e) + transform(c, e) + transform(d, e);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    vector<vector<char> > a(n + 1, vector<char>(m + 1));
    rep(i,n) rep(j,m) cin >> a[i + 1][j + 1];
    int midN = (n + 1) / 2;
    int midM = (m + 1) / 2;
    ll res = 0;
    fore(i,1,midN) {
        fore(j,1,midM) {
            int x = 2 * midN - i + !(n % 2);
            int y = 2 * midM - j + !(m % 2);
            if (i == x && j == y) {
                continue;
            } else if (i == x) {
                char c1 = a[i][j];
                char c2 = a[i][y];
                res += transform(c1, c2);
            } else if (j == y) {
                char c2 = a[i][j];
                char c3 = a[x][j];
                res += transform(c2, c3);
            } else {
                char c1 = a[i][j];
                char c2 = a[i][y];
                char c3 = a[x][j];
                char c4 = a[x][y];
                res += 1ll * min({calc(c1, c2, c3, c4, c1), calc(c1, c2, c3, c4, c2), calc(c1, c2, c3, c4, c3), calc(c1, c2, c3, c4, c4)});
            }
        }
    }
    cout << res << '\n';
    return 0;
}