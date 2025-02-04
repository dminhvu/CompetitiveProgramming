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
    int nTest; cin >> nTest;
    while (nTest--) {
        int xa, ya; cin >> xa >> ya;
        int xb, yb; cin >> xb >> yb;
        int xf, yf; cin >> xf >> yf;
        if (xa == xf && xf == xb && ((ya < yf && yf < yb) || (yb < yf && yf < ya))) {
            cout << abs(xa - xb) + abs(ya - yb) + 2 << '\n';
        } else if (ya == yf && yf == yb && ((xa < xf && xf < xb) || (xb < xf && xf < xa))) {
            cout << abs(xa - xb) + abs(ya - yb) + 2 << '\n';
        } else {
            cout << abs(xb - xa) + abs(yb - ya) << '\n';
        }
    }
    return 0;
}