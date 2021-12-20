#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < int(n); i++)
#define fore(i,a,b) for (int i = int(a); i <= int(b); i++)
#define ford(i,a,b) for (int i = int(a); i >= int(b); i--)
#define ll int64_t
#define sz(x) int(x.size())

using namespace std;
template<class t, class u> bool maxi(t &a, u b){ if (a < b){ a = b; return 1;} return 0;}
template<class t, class u> bool mini(t &a, u b){ if (a > b){ a = b; return 1;} return 0;}
const ll MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<ll> a(n);
    int count_neg = 0;
    int count_zero = 0;
    rep(i,n) {
        cin >> a[i];
        if (a[i] < 0) count_neg += 1;
        if (a[i] == 0) count_zero += 1;
    }
    ll prod = 1;
    int id = -1;
    if (count_zero > 1) {
        cout << 0 << '\n';
        return 0;
    } else if (count_zero == 1 && count_neg % 2 == 0) {
        rep(i,n) {
            if (a[i] == 0) {
                id = i;
            }
        }
    } else if (count_neg & 1) {
        for (int i = 0; i < n; i++) {
            if (a[i] < 0) {
                if (id == -1) {
                    id = i;
                } else {
                    if (a[i] > a[id]) {
                        id = i;
                    }
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (i == id) continue;
        prod = (prod % MOD * a[i] % MOD) % MOD;
    }
    cout << prod << '\n';
    return 0;
}