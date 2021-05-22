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
    freopen("input.txt","r",stdin);
    int t; cin >> t;
    while (t--) {
        string s; int n, k;
        cin >> n >> k >> s;
        if (k == 0) {
            cout << "YES\n";
            continue;
        }
        bool f = 1;
        int l = 0, r = n - 1;
        while (l <= r) {
            if (k) {
                if (s[l] != s[r]) {
                    f = 0;
                    break;
                }
                --k;
            } else {
                break;
            }
        }
        cout << (f ? "YES\n" : "NO\n");
    }
    return 0;
}