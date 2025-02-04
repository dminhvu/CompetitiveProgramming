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
        vector<ll> a(n);
        rep(i,n) cin >> a[i];
        sort(a.begin(), a.end(), greater<ll>());
        bool found = false;
        ll prefsum = 0, suffsum = 0;
        for (int i = 0, j = n - 1; i <= j; i++, j--) {
            suffsum += a[j];
            if (prefsum > suffsum) {
                found = true;
                break;
            }
            prefsum += a[i];
        }
        if (found) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}