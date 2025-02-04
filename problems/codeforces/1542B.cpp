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
        ll n, a, b; cin >> n >> a >> b;
        if (a == 1) {
            if ((n - 1) % b == 0) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
            continue;
        }
        bool found = 0;
        ll cnt = 1;
        while (cnt <= n) {
            if ((n - cnt) % b == 0) {
                found = 1;
                break;
            }
            cnt *= a;
        }
        cout << (found ? "YES\n" : "NO\n");
    }
    return 0;
}