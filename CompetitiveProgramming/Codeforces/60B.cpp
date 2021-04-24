#include<bits/stdc++.h>

using namespace std;
const int N = 15;

int k, n, m;
char a[N][N][N];
bool vis[N][N][N];
int ans = 0;

void dfs(int x, int u, int v){
    vis[x][u][v] = 1;
    ans += (a[x][u][v]=='.');
    if (u>1 && !vis[x][u - 1][v] && (x==k || (x<k && a[x + 1][u][v]=='#'))) dfs(x, u - 1, v);
    if (u<n && !vis[x][u + 1][v] && (x==k || (x<k && a[x + 1][u][v]=='#'))) dfs(x, u + 1, v);
    if (v>1 && !vis[x][u][v - 1] && (x==k || (x<k && a[x + 1][u][v]=='#'))) dfs(x, u, v - 1);
    if (v<m && !vis[x][u][v + 1] && (x==k || (x<k && a[x + 1][u][v]=='#'))) dfs(x, u, v + 1);
    if (x>1 && a[x - 1][u][v]=='.' && !vis[x - 1][u][v]) dfs(x - 1, u, v);
    if (x<k && a[x + 1][u][v]=='.' && !vis[x + 1][u][v]) dfs(x + 1, u, v);
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("input.txt","r",stdin);
    cin >> k >> m >> n;
    for(int i=1; i<=k; i++){
        for(int j=1; j<=n; j++){
            for(int l=1; l<=m; l++){
                cin >> a[i][j][l];
            }
        }
    }
    int tx, ty;
    cin >> tx >> ty;
    memset(vis,0,sizeof vis);
    dfs(0, tx, ty);
    cout << ans;
    return 0;
}