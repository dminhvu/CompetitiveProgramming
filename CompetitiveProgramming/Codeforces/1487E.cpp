#include<bits/stdc++.h>

using namespace std;
const int N = 15e4 + 5;
const int inf = 1e9;

struct myData{
    int v, w;
    bool operator < (const myData &oth) const {
        return w < oth.w;
    }
};

vector<int> a[4][N];
int n[4], dist[4][N];
map<pair<int, int>, int> mp[3];

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    for (int i = 0; i < 4; i++) cin >> n[i];
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < n[i]; j++) cin >> a[i][j];
    }
    int m1, m2, m3;
    cin >> m1;
    for (int i = 0; i < m1; i++) {
        int x, y; cin >> x >> y;
        mp[0][{x, y}] = 1;
    }
    cin >> m2;
    for (int i = 0; i < m2; i++) {
        int x, y; cin >> x >> y;
        mp[1][{x, y}] = 1;
    }
    cin >> m3;
    for (int i = 0; i < m3; i++) {
        int x, y; cin >> x >> y;
        mp[2][{x, y}] = 1;
    }
    priority_queue<myData> pq;
    memset(dist,inf,sizeof dist);
    for (int i = 0; i < n[0]; i++) {
        pq.push({1, a[0][i]});
        dist[0][i] = a[0][i];
    }
    while (pq.size()) {
        int u = pq.top().v;
        int w = pq.top().w;
        pq.pop();
        for (int i = 0; i < n[u]; i++) {
            if (mp[u - 1][])
        }
    }
    return 0;
}