#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < int(n); i++)
#define fore(i,a,b) for (int i = int(a); i <= int(b); i++)
#define ford(i,a,b) for (int i = int(a); i >= int(b); i--)
#define ll int64_t
#define sz(x) int(x.size())

using namespace std;
template<class t, class u> bool maxi(t &a, u b){ if (a < b){ a = b; return 1;} return 0;}
template<class t, class u> bool mini(t &a, u b){ if (a > b){ a = b; return 1;} return 0;}
const int MAXN = 2e7 + 5;

bool is_prime(int n) {
    if (n == 2 || n == 3) return true;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    vector<int> prime;
    fore(i,2,sqrt(MAXN) + 100) {
        if (is_prime(i)) {
            prime.push_back(i);
        }
    }
    rep(i,n) {
        int j = 0;
        while (j < prime.size() && prime[j] * prime[j] <= a[i]) {
            while (a[i] % (prime[j] * prime[j]) == 0) {
                a[i] /= prime[j];
            }
            j += 1;
        }
    }
    ll ans = 0;
    ll count = 0;
    sort(a.begin(), a.end());
    rep(i,n) {
        if (i == 0) count += 1;
        else {
            if (a[i] == a[i - 1]) count += 1;
            else {
                ans += 1ll * count * (count - 1) / 2ll;
                count = 1;
            }
        }   
    }
    if (count) ans += 1ll * count * (count - 1) / 2ll;
    cout << ans << '\n';
    return 0;
}