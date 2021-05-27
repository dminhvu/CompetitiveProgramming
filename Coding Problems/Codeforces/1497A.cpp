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
        vector<int> a(n);
        rep(i,n) cin >> a[i];
        set<int> s;
        for(int &x: a) {
            if (s.find(x) == s.end()) {
                s.insert(x);
                x = -1;
            }
        }
        vector<int> ans;
        for(int x: s) ans.pb(x);
        for(int x: a) if (x != -1) ans.pb(x);
        for(int x: ans) cout << x << " ";
        cout << '\n';
    }
    return 0;
}