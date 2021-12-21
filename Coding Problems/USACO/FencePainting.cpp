#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < int(n); i++)
#define fore(i,a,b) for (int i = int(a); i <= int(b); i++)
#define ford(i,a,b) for (int i = int(a); i >= int(b); i--)
#define ll int64_t
#define sz(x) int(x.size())
#define OJ

using namespace std;
template<class t, class u> bool maxi(t &a, u b){ if (a < b){ a = b; return 1;} return 0;}
template<class t, class u> bool mini(t &a, u b){ if (a > b){ a = b; return 1;} return 0;}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    #if defined(OJ)
    freopen("paint.in","r",stdin);
    freopen("paint.out","w",stdout);
    #endif // 
    int a, b, c, d; cin >> a >> b >> c >> d;
    int ans = b - a + d - c;
    ans -= max(0, min(b, d) - max(a, c));
    cout << ans;
    return 0;
}