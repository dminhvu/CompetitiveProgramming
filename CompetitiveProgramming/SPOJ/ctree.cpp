#include<bits/stdc++.h>

using namespace std;
const int N = 1e4 + 5;
const int inf = 1e9;

vector<int> adj[N];
int n;
int col[N];
int dp[N][4];

void dfs(int u, int pa = 0){
    int minVal = inf;
    for (int j = 1; j <= 3; j++) {
        if (j == col[pa]) continue;
        col[u] = j;
        dp[u][j] = j;
        for (int v: adj[u]) {
            if (v == pa) continue;
            int mn = inf;
            dfs(v, u);
            for (int k = 1; k <= 3; k++) {
                if (j == k) continue;
                mn = min(mn, dp[v][k]);
            }
            dp[u][j] += mn;
        }
        if (dp[u][j] < minVal) {
            col[u] = min(col[u], j);
            minVal = dp[u][j];
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("input.txt","r",stdin);
    cin >> n;
    for (int i = 1; i < n; i++) {
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs(1);
    int res = inf;
    for (int i = 1; i <= 3; i++) res = min(res, dp[1][i]);
    for (int i = 1; i <= 3; i++) cout << dp[1][i] << " ";
    cout << res << '\n';
    for (int i = 1; i <= n; i++) cout << col[i] << '\n';
    return 0;
}