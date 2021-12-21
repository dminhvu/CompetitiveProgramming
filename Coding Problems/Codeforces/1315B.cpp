#include<bits/stdc++.h>
#define ntu

using namespace std;
const int N = 1e5 + 5;

int n, a, b, m;
int64_t dp[N];
string s;

void Solve()
{
    cin >> a >> b >> m;
    cin >> s;
    n = s.size(); s = ' ' + s;
    //memset(dp,0x3f3f,sizeof dp);
    dp[n] = 0;
    for (int i=n-1; i>=1; i--) if (s[i]==s[i + 1] && i!=n-1) dp[i] = dp[i + 1];
    else dp[i] = dp[i + 1] + 1ll * (s[i]=='A' ? a : b);
    int res = n;
    for (int i=n; i>=1; i--) if (dp[i] <= m) res = min(res, i);
    cout << res << '\n';
}

int main()
{
#ifdef ntu
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int nTest; cin >> nTest;
    while (nTest--) Solve();
    return 0;
}