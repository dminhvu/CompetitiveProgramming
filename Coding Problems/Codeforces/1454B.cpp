#include<bits/stdc++.h>

using namespace std;
const int N = 2e5 + 5;

int cnt[N];
vector<int> pos[N];

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("input.txt","r",stdin);
    int nTest; cin >> nTest;
    while (nTest--)
    {
        int n; cin >> n;
        for (int i=1; i<=n; i++) cnt[i] = 0, pos[i].clear();
        for (int i=1; i<=n; i++)
        {
            int x; cin >> x;
            cnt[x]++;
            pos[x].push_back(i);
        }
        bool f = 0;
        for (int i=1; i<=n; i++)
        {
            if (cnt[i]==1)
            {
                f = 1;
                cout << pos[i].back();
                break;
            }
        }
        if (!f) cout << -1;
        cout << '\n';
    }
    return 0;
}