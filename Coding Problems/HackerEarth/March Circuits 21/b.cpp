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
        int n; cin >> n;
        vector<int> a(n + 1);
        rep(i,n) cin >> a[i + 1];
        vector<int> left(n + 1), right(n + 1);
        fore(i,1,n) {
            left[i] = i;
            while (left[i] > 1 && a[left[i] - 1] > a[left[i]]) left[i] = left[left[i] - 1];
        }
        ford(i,n,1) {
            right[i] = i;
            while (right[i] < n && a[right[i] + 1] > a[right[i]]) right[i] = right[right[i] + 1];
        }
        fore(i,1,n) {
            cout << right[i] - left[i] + 1 << " ";
        }
        cout << '\n';
    }
    return 0;
}