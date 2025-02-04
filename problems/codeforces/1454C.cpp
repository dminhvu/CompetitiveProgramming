#include<bits/stdc++.h>

using namespace std;
const int N = 2e5 + 5;

int cnt[N];
vector<int> pos[N];

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // freopen("input.txt","r",stdin);
    int nTest; cin >> nTest;
    while (nTest--)
    {
        int n; cin >> n;
        int ans = n;
        for (int i=1; i<=n; i++) pos[i].clear(), cnt[i] = 0, pos[i].push_back(0);
        for (int i=1; i<=n; i++)
        {
            int x; cin >> x;
            pos[x].push_back(i);
        }
        for (int i=1; i<=n; i++) pos[i].push_back(n + 1);
        for (int i=1; i<=n; i++)
        {
            if (pos[i].size()==2) continue;
            int cur = 0;
            //cout << i << " ";
            //for (int j=0; j<pos[i].size(); j++) cout << pos[i][j] << " ";
            for (int j=1; j<pos[i].size(); j++)
            {
                if (pos[i][j]!=pos[i][j - 1] + 1) cur++;
            }
            //cout << '\n';
            ans = min(ans, cur);
        }
        cout << ans << '\n';
    }
    return 0;
}