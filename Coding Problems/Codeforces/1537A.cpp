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
        int n; cin >> n;
        int total = 0;
        int sign = 1;
        rep(i,n) {
            int foo; cin >> foo;
            total += foo;
        }
        if (total < 0) {
            cout << 1 << '\n';
        } else if (total == n) {
            cout << 0 << '\n';
        } else if (total < n) {
            cout << 1 << '\n';
        } else {
            cout << total - n << '\n';
        }
    }
    return 0;
}