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

int64_t binpow(int64_t a, int64_t b) {
    if (b == 0) return 1;
    int64_t tmp = pow(a, b / 2ll);
    tmp *= tmp;
    if (b & 1ll) tmp *= a;
    return tmp;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // freopen("input.txt","r",stdin);
    int t; cin >> t;
    function<int(int64_t)> calc = [&] (int64_t x) {
        int sum = 0;
        while (x) {
            sum += x % 10;
            x /= 10;
        }
        return sum;
    };
    while (t--) {
        int64_t n; cin >> n;
        int s; cin >> s;
        int cnt = 0;
        int64_t m = n;
        while (calc(n) > s) {
            ++cnt;
            int64_t sub = ((n / binpow(10ll, cnt - 1)) % 10ll) * binpow(10ll, cnt - 1);
            int64_t add = binpow(10ll, cnt);
            if (sub != 0) {
                n -= sub;
                n += add;
            }
        }
        cout << n - m << '\n';
    }
    return 0;
}