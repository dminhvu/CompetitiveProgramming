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
        int n, m; cin >> n >> m;
        vector<int> a(n + 2, 0);
        rep(i,n) {
            char c; cin >> c;
            a[i + 1] = c - '0';
        }
        fore(i,1,min(n,m)) {
            vector<int> b(n + 2, 0);
            fore(i,1,n) b[i] = a[i];
            fore(i,1,n) {
                if (a[i] == 1) continue;
                if (a[i - 1] + a[i + 1] == 1) {
                    b[i] = 1;
                }
            }
            fore(i,1,n) a[i] = b[i];
        }
        fore(i,1,n) cout << a[i];
        cout << '\n';
    }
    return 0;
}