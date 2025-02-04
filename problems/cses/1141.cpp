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
    int n; cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    map<int, int> cnt;
    int j = 0;
    int ans = 1;
    rep(i,n) {
        while (cnt[a[i]] == 1) {
            cnt[a[j]] -= 1;
            j += 1;
        }
        cnt[a[i]] = 1;
        ans = max(ans, i - j + 1);
    }
    cout << ans;
    return 0;
}