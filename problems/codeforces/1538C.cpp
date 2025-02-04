#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < int(n); i++)
#define fore(i,a,b) for (int i = int(a); i <= int(b); i++)
#define ford(i,a,b) for (int i = int(a); i >= int(b); i--)
#define ll int64_t
#define sz(x) int(x.size())

using namespace std;
template<class t, class u> bool maxi(t &a, u b){ if (a < b){ a = b; return 1;} return 0;}
template<class t, class u> bool mini(t &a, u b){ if (a > b){ a = b; return 1;} return 0;}

const int N = 1e9 + 5;
map<int, int> BIT;

void update(int pos) {
    while (pos < N) {
        BIT[pos]++;
        pos += (pos & (-pos));
    }
}

int get(int pos) {
    if (pos < 0) return 0;
    if (pos >= N) return 0;
    int ans = 0;
    while (pos > 0) {
        ans += BIT[pos];
        pos -= (pos & (-pos));
    }
    return ans;
}

int main() {
    // freopen64("input.txt","r",stdin);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int nTest; cin >> nTest;
    while (nTest--) {
        int n, l, r; cin >> n >> l >> r;
        vector<int> a(n);
        rep(i,n) cin >> a[i];
        ll ans = 0;
        rep(i,n) {
            ans += 1ll * get(r - a[i]) - 1ll * get(l - a[i] - 1);
            update(a[i]);
        }
        BIT.clear();
        cout << ans << '\n';
    }
    return 0;
}