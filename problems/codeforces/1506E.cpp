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
const int N = 2e5 + 5;

int a[N];
int n;

void findMin() {
    vector<int> ans(n, -1);
    vector<bool> f(n, 0);
    rep(i,n) {
        if (!f[a[i]]) {
            ans[i] = a[i];
        }
        f[a[i]] = 1;
    }
    vector<int> v;
    ford(i,n-1,0) if (!f[i]) v.pb(i);
    rep(i,n) {
        if (ans[i] == -1) {
            ans[i] = v.back();
            v.pop_back();
        }
    }
    rep(i,n) cout << ans[i] + 1 << " ";
    cout << '\n';
}

void findMax() {
    vector<int> ans(n, -1);
    vector<bool> f(n, 0);
    rep(i,n) {
        if (!f[a[i]]) {
            ans[i] = a[i];
        }
        f[a[i]] = 1;
    }
    int curMax = a[0];
    vector<int> v;
    rep(i,a[0]) v.pb(i);
    rep(i,n) {
        if (curMax != a[i]) {
            int cnt = a[i - 1] + 1;
            while (cnt < a[i]) v.pb(cnt++);
        }
        maxi(curMax, a[i]);
        if (ans[i] == -1) {
            ans[i] = v.back();
            v.pop_back();
        }
    }
    rep(i,n) cout << ans[i] + 1 << " ";
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // freopen("input.txt","r",stdin);
    int t; cin >> t;
    while (t--) {
        cin >> n;
        rep(i,n) {
            cin >> a[i];
            --a[i];
        }
        findMin();
        findMax();
    }
    return 0;
}