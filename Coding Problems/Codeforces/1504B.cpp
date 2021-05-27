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
        int n; cin >> n;
        vector<int> a(n + 1, 0), b(n + 1, 0);
        string s; cin >> s;
        fore(i,1,n) a[i] = s[i - 1] - '0';
        cin >> s;
        fore(i,1,n) b[i] = s[i - 1] - '0';
        int flips = 0;
        bool f = 1;
        int cnt1 = 0, cnt0 = 0;
        fore(i,1,n) cnt1 += a[i] == 1, cnt0 += a[i] == 0;
        ford(i,n,1) {
            int cur = (a[i] + flips) % 2;
            if (cur != b[i]) {
                if (cnt1 != cnt0) {
                    f = 0;
                    break;
                }
                flips += 1;
                swap(cnt1, cnt0);
            }
            cnt1 -= ((a[i] + flips) % 2 == 1);
            cnt0 -= ((a[i] + flips) % 2 == 0);
            // fore(i,1,n) cout << (a[i] + flips) % 2;
            // cout << '\n';
        }
        if (f) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}