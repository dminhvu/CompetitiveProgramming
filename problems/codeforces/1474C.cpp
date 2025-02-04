#include <bits/stdc++.h>

using namespace std;
const int N = 2e6 + 5;

int n;
vector<int> adj[N];
bool vis[N];

bool dfs(int u, int h = 2)
{
    //cout << u << " ";
    if (h==n) return true;
    for (int v : adj[u])
    {
        if (vis[v] || vis[u - v])
            continue;
        vis[v] = 1;
        vis[u - v] = 1;
        if (dfs(v, h + 1)) return true;
        vis[v] = 0;
        vis[u - v] = 0;
    }
    //cout << '\n';
    return false;
}

int main()
{
    freopen("input.txt","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int nTest;
    cin >> nTest;
    while (nTest--)
    {
        cin >> n;
        n *= 2;
        vector<int> a(n);
        vector<int> b(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        sort(a.begin(), a.end());
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                
            }
        }
        
        bool f = 0;
        for (int i = a[n - 1] * 2; i >= 1; i--)
        {
            memset(vis,0,sizeof vis);
            vis[i] = 1;
            if (dfs(i))
            {
                cout << "YES\n";
                cout << i << '\n';
                f = 1;
                break;
            }
        }
        if (!f) cout << "NO\n";
    }
    return 0;
}