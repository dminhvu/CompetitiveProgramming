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
        vector<int> a(n + 2, 0), b(n + 1, 0);
        fore(i,1,n) cin >> a[i] >> b[i];
        int cur = 0;
        vector<int> c(n + 1, 0);
        fore(i,1,n) cin >> c[i];
        int arr, dep = 0;
        fore(i,1,n) {
            arr = dep + a[i] - b[i - 1] + c[i];
            dep = max(b[i], arr + (b[i] - a[i] + 1) / 2);
            // cout << dep << " ";
        }
        cout << arr << '\n';
    }
    return 0;
}