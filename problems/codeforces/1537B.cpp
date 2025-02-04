#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < int(n); i++)
#define fore(i,a,b) for (int i = int(a); i <= int(b); i++)
#define ford(i,a,b) for (int i = int(a); i >= int(b); i--)
#define ll int64_t
#define sz(x) int(x.size())

using namespace std;
template<class t, class u> bool maxi(t &a, u b){ if (a < b){ a = b; return 1;} return 0;}
template<class t, class u> bool mini(t &a, u b){ if (a > b){ a = b; return 1;} return 0;}

// ll calcDist(int x, int y, int s, int t) {
//     return 1ll * (abs(x - s) + abs(y - t));
// }

// void update(int &x1, int &y1, int &x2, int &y2, int s1, int t1, int s2, int t2) {
//     x1 = s1;
//     y1 = t1;

//     x2 = s2;
//     y2 = t2;
// }

int main() {
    // freopen64("input.txt","r",stdin);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int nTest; cin >> nTest;
    while (nTest--) {
        int n, m, x, y; cin >> n >> m >> x >> y;
        // Naive solution
        // int ansX1 = -1, ansY1 = -1, ansX2 = -1, ansY2 = -1;
        // ll maxDist = -1;
        // if (maxi(maxDist, calcDist(1, 1, x, y))) {
        //     update(ansX1, ansY1, ansX2, ansY2, 1, 1, 1, 1);
        // }
        // if (maxi(maxDist, calcDist(1, m, x, y))) {
        //     update(ansX1, ansY1, ansX2, ansY2, 1, m, 1, m);
        // }
        // if (maxi(maxDist, calcDist(n, 1, x, y))) {
        //     update(ansX1, ansY1, ansX2, ansY2, n, 1, n, 1);
        // }
        // if (maxi(maxDist, calcDist(n, m, x, y))) {
        //     update(ansX1, ansY1, ansX2, ansY2, n, m, n, m);
        // }
        // if (maxi(maxDist, calcDist(1, 1, x, y) + calcDist(1, 1, 1, m) + calcDist(1, m, x, y))) {
        //     update(ansX1, ansY1, ansX2, ansY2, 1, 1, 1, m);
        // }
        // if (maxi(maxDist, calcDist(1, 1, x, y) + calcDist(1, 1, n, 1) + calcDist(n, 1, x, y))) {
        //     update(ansX1, ansY1, ansX2, ansY2, 1, 1, n, 1);
        // }
        // if (maxi(maxDist, calcDist(1, 1, x, y) + calcDist(1, 1, n, m) + calcDist(n, m, x, y))) {
        //     update(ansX1, ansY1, ansX2, ansY2, 1, 1, n, m);
        // }
        // if (maxi(maxDist, calcDist(1, m, x, y) + calcDist(1, m, n, 1) + calcDist(n, 1, x, y))) {
        //     update(ansX1, ansY1, ansX2, ansY2, 1, m, n, 1);
        // }
        // if (maxi(maxDist, calcDist(1, m, x, y) + calcDist(1, m, n, m) + calcDist(n, m, x, y))) {
        //     update(ansX1, ansY1, ansX2, ansY2, 1, m, n, m);
        // }
        // if (maxi(maxDist, calcDist(n, 1, x, y) + calcDist(n, 1, n, m) + calcDist(n, m, x, y))) {
        //     update(ansX1, ansY1, ansX2, ansY2, n, 1, n, m);
        // }
        // cout << ansX1 << " " << ansY1 << " " << ansX2 << " " << ansY2 << '\n';
        cout << 1 << " " << 1 << " " << n << " " << m << '\n';
    }
    return 0;
}