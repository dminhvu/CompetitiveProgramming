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
        int n, k; cin >> n >> k;
        if (k > n) {
            cout << "NO\n";
            continue;
        }
        if (n & 1) {
            if (k & 1) {
                cout << "YES\n";
                for(int i = 1; i < k; i++) cout << 1 << " ";
                cout << n - (k - 1) << '\n';
            } else {
                cout << "NO\n";
            }
        } else {
            if (k & 1) {
                if (2 * k <= n) {
                    cout << "YES\n";
                    for(int i = 1; i < k; i++) cout << 2 << " ";
                    cout << n - 2 * (k - 1) << '\n';
                } else {
                    cout << "NO\n";
                }
            } else {
                cout << "YES\n";
                for(int i = 1; i < k; i++) cout << 1 << " ";
                cout << n - (k - 1) << '\n';
            }
        }
    }
    return 0;
}