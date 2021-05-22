#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;

int n;
vector<int> a[N];
int dp[N][2];
int pa[N];
int ans;

int main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    //freopen("input.txt","r",stdin);
    int nTest; cin >> nTest;
    while(nTest--)
    {
        cin >> n;
        dp[1][0] = 0, dp[1][1] = 1, pa[1] = 0;
        for (int i=2; i<=n; i++){
            int x; cin >> x;
            pa[i] = x;
            a[x].push_back(i);
            dp[i][0] = 0, dp[i][1] = 1;
            int pp = pa[i];
            while (pp)
            {
                dp[pp][0] = 0, dp[pp][1] = 1;
                for(int y: a[pp]) dp[pp][0] += dp[y][1];
                for(int y: a[pp]) dp[pp][1] += min(dp[y][1], dp[y][0]);
                pp = pa[pp];
            }
            ans = min(dp[1][0], dp[1][1]);
            if(i>=4 && ans==1) ++ans;
            ++ans;
            cout << ans << " ";
        }
        for (int i=0; i<N; i++) a[i].clear();
        cout << '\n';
    }
    return 0;
}