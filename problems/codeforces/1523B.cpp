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
    int nTest; cin >> nTest;
    while (nTest--) {
        int n; cin >> n;
        rep(i,n) {
            int foo; cin >> foo;
        }
        cout << 6 * (n / 2) << '\n';
        fore(i,1,n/2) {
            rep(j,3) {
                cout << "1 " << i * 2 - 1 << " " << i * 2 << '\n';
                cout << "2 " << i * 2 - 1 << " " << i * 2 << '\n';
            }
        }
    }
    return 0;
}