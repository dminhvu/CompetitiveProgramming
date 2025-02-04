#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < int(n); i++)
#define fore(i,a,b) for (int i = int(a); i <= int(b); i++)
#define ford(i,a,b) for (int i = int(a); i >= int(b); i--)
#define ll int64_t
#define sz(x) int(x.size())

using namespace std;
template<class t, class u> bool maxi(t &a, u b){ if (a < b){ a = b; return 1;} return 0;}
template<class t, class u> bool mini(t &a, u b){ if (a > b){ a = b; return 1;} return 0;}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<int> p(n);
    rep(i,n) {
        cin >> p[i];
        // p[i] -= 1;
    }
    vector<vector<int> > color(n, vector<int>(n, 0));
    rep(i,n) {
        int cur = i;
        queue<pair<int, int> > q;
        q.push({cur, cur});
        color[cur][cur] = p[cur];
        int count = 1;
        while (q.size()) {
            int u = q.front().first;
            int v = q.front().second;
            q.pop();
            if (count >= p[cur]) break;
            if (v - 1 >= 0 && !color[u][v - 1]) {
                color[u][v - 1] = p[cur];
                count += 1;
                q.push({u, v - 1});
            } else if (u + 1 < n && !color[u + 1][v]) {
                color[u + 1][v] = p[cur];
                count += 1;
                q.push({u + 1, v});
            }
        }
    }
    rep(i,n) {
        rep(j,i+1) {
            cout << color[i][j] << " ";
        }
        cout << '\n';
    }
    return 0;
}