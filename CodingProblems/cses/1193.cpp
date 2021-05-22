#include<bits/stdc++.h>

using namespace std;
const int N = 1e3 + 5;

struct myData{
    int u, v;
};

int trace[N][N][2];

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    string s[n];
    for(int i=0; i<n; i++) cin >> s[i];
    int sX, sY, tX, tY;
    string ans = "";
    bool f = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if (s[i][j]=='A'){
                sX = i;
                sY = j;
            }
            if (s[i][j]=='B'){
                tX = i;
                tY = j;
            }
        }
    }
    memset(trace,255,sizeof trace);
    queue<myData> q;
    q.push({sX, sY});
    s[sX][sY] = '#';
    while (q.size()){
        int u = q.front().u;
        int v = q.front().v;
        s[u][v] = '#';
        if (u==tX && v==tY){
            f = 1;
            break;
        }
        q.pop();
        if (u>0 && s[u - 1][v]!='#'){
            q.push({u - 1, v});
            trace[u - 1][v][0] = u;
            trace[u - 1][v][1] = v;
        }
        if (u<n-1 && s[u + 1][v]!='#'){
            q.push({u + 1, v});
            trace[u + 1][v][0] = u;
            trace[u + 1][v][1] = v;
        }
        if (v>0 && s[u][v - 1]!='#'){
            q.push({u, v - 1});
            trace[u][v - 1][0] = u;
            trace[u][v - 1][1] = v;
        }
        if (v<m-1 && s[u][v + 1]!='#'){
            q.push({u, v + 1});
            trace[u][v + 1][0] = u;
            trace[u][v + 1][1] = v;
        }
    }
    if (!f) cout << "NO";
    else{
        cout << "YES\n";
        int x = tX, y = tY;
        do {
            if (trace[x][y][0]==x - 1) ans += "D";
            else if (trace[x][y][0]==x + 1) ans += "U";
            else if (trace[x][y][1]==y - 1) ans += "R";
            else if (trace[x][y][1]==y + 1) ans += "L";
            x = trace[x][y][0];
            y = trace[x][y][1];
        } while (x!=sX || y!=sY);
        cout << ans.size() << '\n';
        cout << ans;
    }
    return 0;
}