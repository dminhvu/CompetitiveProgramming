#include<bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int nTest; cin >> nTest;
    while (nTest--){
        int n; cin >> n;
        vector<vector<int> > adj(n);
        vector<int64_t> dp(n, 0), a(n);
        for(int i=0; i<n; i++){
            int x; cin >> x;
            a[i] = x;
            if (i + x < n) adj[i + x].push_back(i);
        }
        int64_t res = 0;
        for(int i=0; i<n; i++){
            dp[i] = a[i];
            for(int v: adj[i]){
                dp[i] = max(dp[i], dp[v] + a[i]);
            }
            res = max(res, dp[i]);
        }
        cout << res << '\n';
    }
    return 0;
}