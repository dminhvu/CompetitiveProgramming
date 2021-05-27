#include<bits/stdc++.h>

using namespace std;
const int N = 55;
const int inf = 1e9;

int n;
bool vis[N][N];
int a[N][N], f[10];
int sX, sY, tX, tY;
int res;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("input.txt","r",stdin);
    int nTest; cin >> nTest;
    while (nTest--){
        cin >> n;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++) cin >> a[i][j];
        }
        cin >> sX >> sY >> tX >> tY;
        queue<myData> q;
        q.push({sX, sY, (1<<a[sX][sY])});
        while (q.size()){
            int u = q.front()
        }
    }
    return 0;
}