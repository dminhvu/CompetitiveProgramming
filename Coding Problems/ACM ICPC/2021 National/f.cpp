#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < int(n); i++)
#define fore(i,a,b) for (int i = int(a); i <= int(b); i++)
#define ford(i,a,b) for (int i = int(a); i >= int(b); i--)
#define ll int64_t
#define sz(x) int(x.size())

using namespace std;
template<class t, class u> bool maxi(t &a, u b){ if (a < b){ a = b; return 1;} return 0;}
template<class t, class u> bool mini(t &a, u b){ if (a > b){ a = b; return 1;} return 0;}

// const int N = 1e9;

// int a[N];

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    ll n; cin >> n;
    n -= 1;
    ll ans = (1ll << n);
    cout << ans;
    return 0;
}