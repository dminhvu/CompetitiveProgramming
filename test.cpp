#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < int(n); i++)
#define fore(i,a,b) for (int i = int(a); i <= int(b); i++)
#define ford(i,a,b) for (int i = int(a); i >= int(b); i--)
#define ll int64_t
#define sz(x) int(x.size())

using namespace std;
template<class t, class u> bool maxi(t &a, u b){ if (a < b){ a = b; return 1;} return 0;}
template<class t, class u> bool mini(t &a, u b){ if (a > b){ a = b; return 1;} return 0;}

int cnt[100][100];

void calc(int x, int y) {
    if(x == 0 || y == 0) {
        cnt[x][y]++;
        return;
    }
    calc(x - 1, y);
    calc(x, y - 1);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    memset(cnt,0,sizeof cnt);
    int n = 5;
    int m = 5;
    calc(n, m);
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= m; j++) {
            cout << cnt[i][j] << " ";
        }
        cout << '\n';
    }
    return 0;
}