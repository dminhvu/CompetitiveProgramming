#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < int(n); i++)
#define fore(i,a,b) for (int i = int(a); i <= int(b); i++)
#define ford(i,a,b) for (int i = int(a); i >= int(b); i--)
#define ll int64_t
#define sz(x) int(x.size())

using namespace std;
template<class t, class u> bool maxi(t &a, u b){ if (a < b){ a = b; return 1;} return 0;}
template<class t, class u> bool mini(t &a, u b){ if (a > b){ a = b; return 1;} return 0;}

bool isPrime(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    for(int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    // freopen64("input.txt","r",stdin);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int nTest; cin >> nTest;
    while (nTest--) {
        int a, b, c; cin >> a >> b >> c;
        int z = 1;
        rep(i,c-1) z *= 10;
        while (!isPrime(z)) z++;
        int x = 1;
        rep(i,a-1) x *= 10;
        x = ((x + z - 1) / z) * z;
        int y = 1;
        rep(i,b-1) y *= 10;
        y = ((y + z - 1) / z) * z;
        while (__gcd(x, y) != z) y++;
        cout << x << " " << y << '\n';
    }
    return 0;
}