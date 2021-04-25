#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < int(n); i++)
#define fore(i,a,b) for (int i = int(a); i <= int(b); i++)
#define ford(i,a,b) for (int i = int(a); i >= int(b); i--)
#define ll int64_t
#define sz(x) int(x.size())

using namespace std;
template<class t, class u> bool maxi(t &a, u b){ if (a < b){ a = b; return 1;} return 0;}
template<class t, class u> bool mini(t &a, u b){ if (a > b){ a = b; return 1;} return 0;}

struct myData
{
    int val, x, y;
    bool operator < (const myData &oth) const {
        return val < oth.val;
    }
};

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // freopen("input.txt","r",stdin);
    int nTest; cin >> nTest;
    while (nTest--) {
        int n, m; cin >> n >> m;
        vector<vector<int>> a(n, vector<int>(m,0));
        rep(i,n) rep(j,m) cin >> a[i][j];
        vector<myData> v;
        rep(i,n) rep(j,m) v.push_back({a[i][j], i, j});
        sort(v.begin(), v.end());
        rep(i,m) {
            int x = v[i].x;
            int y = v[i].y;
            rep(j,m) {
                if (v[j].x == x && v[j].y == i) {
                    v[j].y = y;
                    break;
                }
            }
            swap(a[x][y], a[x][i]);
            v[i].y = i;
        }
        rep(i,n) {
            rep(j,m) {
                cout << a[i][j] << " ";
            }
            cout << '\n';
        }
    }
    return 0;
}