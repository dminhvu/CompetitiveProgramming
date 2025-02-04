#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < int(n); i++)
#define fore(i,a,b) for (int i = int(a); i <= int(b); i++)
#define ford(i,a,b) for (int i = int(a); i >= int(b); i--)
#define ll int64_t
#define sz(x) int(x.size())

using namespace std;
template<class t, class u> bool maxi(t &a, u b){ if (a < b){ a = b; return 1;} return 0;}
template<class t, class u> bool mini(t &a, u b){ if (a > b){ a = b; return 1;} return 0;}

void solve(int n, int a, int c, int b) {
    if (n == 1) {
        cout << a << " " << c << '\n';
        return;
    }
    solve(n - 1, a, b, c);
    solve(1, a, c, b);
    solve(n - 1, b, c, a);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    cout << (1 << n) - 1 << '\n';
    solve(n, 1, 3, 2);
    return 0;
}