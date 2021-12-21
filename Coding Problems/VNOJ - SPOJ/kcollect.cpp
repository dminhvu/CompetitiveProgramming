#include<bits/stdc++.h>

using namespace std;
const int N = 1e2 + 5;
const int dx[4] = {0, -1, 0, 1};
const int dy[4] = {-1, 0, 1, 0};

int n, m;
char a[N][N];
int Low[N][N], Num[N][N], cnt = 0, cntComp = 0;
vector<pair<int, int> > st;
int comp[N][N], val[N*N];

void dfs(int u, int v){
    Low[u][v] = Num[u][v] = ++cnt;
    st.push_back({u, v});
    for(int i=0; i<4; i++){
        int x = u + dx[i];
        int y = v + dy[i];
        if (x<1 || y<1 || x>n || y>m) continue;
        if (a[x][y]=='#') continue;
        if (i==0 && a[u][v]!='W') continue;
        if (i==1 && a[u][v]!='N') continue;
        if (Num[x][y]){
            Low[u][v] = min(Low[u][v], Num[x][y]);
        }
        else{
            dfs(x, y);
            Low[u][v] = min(Low[u][v], Low[x][y]);
        }
    }
    if (Low[u][v]==Num[u][v]){
        ++cntComp;
        while (1) {
            pair<int, int> cur = st.back();
            st.pop_back();
            comp[cur.first][cur.second] = cntComp;
            if (a[cur.first][cur.second]>='0' && a[cur.first][cur.second]<='9'){
                val[cntComp] += a[cur.first][cur.second] - '0';
            }
            if (cur.first==u && cur.second==v) break;
        }
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("input.txt","r",stdin);
    cin >> n >> m;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++) cin >> a[i][j];
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if (!Num[i][j] && a[i][j]!='#'){
                dfs(i, j);
            }
        }
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++) cout << comp[i][j] << " ";
        cout << '\n';
    }
    for(int i=1; i<=cntComp; i++) cout << val[i] << " ";
    return 0;
}