#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < int(n); i++)
#define fore(i,a,b) for (int i = int(a); i <= int(b); i++)
#define ford(i,a,b) for (int i = int(a); i >= int(b); i--)
#define ll int64_t
#define pb push_back
#define fi first
#define se second
#define sz(x) int(x.size())

using namespace std;
template<class t, class u> bool maxi(t &a, u b){ if (a < b){ a = b; return 1;} return 0;}
template<class t, class u> bool mini(t &a, u b){ if (a > b){ a = b; return 1;} return 0;}
const int N = 1e3 + 5;

int a[N][N];
int r, c;

int calc1() {
    int ans = 0;
    vector<vector<int> > row(r + 2, vector<int>(c + 2, 0));
    vector<vector<int> > col(r + 2, vector<int>(c + 2, 0));
    fore(i,1,r) {
        fore(j,1,c) {
            if (a[i][j] == 1) row[i][j] = row[i][j - 1] + 1;
            else row[i][j] = 0;
        }
    }
    fore(j,1,c) {
        fore(i,1,r) {
            if (a[i][j] == 1) col[i][j] = col[i - 1][j] + 1;
            else col[i][j] = 0;
        }
    }
    fore(i,1,r) {
        fore(j,1,c) {
            if (a[i][j] != 1) continue;
            ans += max(0, min(row[i][j] / 2, col[i][j]) - 1);
            ans += max(0, min(col[i][j] / 2, row[i][j]) - 1);
        }
    }
    return ans;
}

int calc2() {
    int ans = 0;
    vector<vector<int> > row(r + 2, vector<int>(c + 2, 0));
    vector<vector<int> > col(r + 2, vector<int>(c + 2, 0));
    fore(i,1,r) {
        fore(j,1,c) {
            if (a[i][j] == 1) row[i][j] = row[i][j - 1] + 1;
            else row[i][j] = 0;
        }
    }
    fore(j,1,c) {
        ford(i,r,1) {
            if (a[i][j] == 1) col[i][j] = col[i + 1][j] + 1;
            else col[i][j] = 0;
        }
    }
    fore(i,1,r) {
        fore(j,1,c) {
            if (a[i][j] != 1) continue;
            ans += max(0, min(row[i][j] / 2, col[i][j]) - 1);
            ans += max(0, min(col[i][j] / 2, row[i][j]) - 1);
        }
    }
    return ans;
}

int calc3() {
    int ans = 0;
    vector<vector<int> > row(r + 2, vector<int>(c + 2, 0));
    vector<vector<int> > col(r + 2, vector<int>(c + 2, 0));
    fore(i,1,r) {
        ford(j,c,1) {
            if (a[i][j] == 1) row[i][j] = row[i][j + 1] + 1;
            else row[i][j] = 0;
        }
    }
    fore(j,1,c) {
        fore(i,1,r) {
            if (a[i][j] == 1) col[i][j] = col[i - 1][j] + 1;
            else col[i][j] = 0;
        }
    }
    fore(i,1,r) {
        fore(j,1,c) {
            if (a[i][j] != 1) continue;
            ans += max(0, min(row[i][j] / 2, col[i][j]) - 1);
            ans += max(0, min(col[i][j] / 2, row[i][j]) - 1);
        }
    }
    return ans;
}

int calc4() {
    int ans = 0;
    vector<vector<int> > row(r + 2, vector<int>(c + 2, 0));
    vector<vector<int> > col(r + 2, vector<int>(c + 2, 0));
    fore(i,1,r) {
        ford(j,c,1) {
            if (a[i][j] == 1) row[i][j] = row[i][j + 1] + 1;
            else row[i][j] = 0;
        }
    }
    ford(i,r,1) {
        ford(j,c,1) {
            if (a[i][j] == 1) col[i][j] = col[i + 1][j] + 1;
            else col[i][j] = 0;
        }
    }
    fore(i,1,r) {
        fore(j,1,c) {
            if (a[i][j] != 1) continue;
            ans += max(0, min(row[i][j] / 2, col[i][j]) - 1);
            ans += max(0, min(col[i][j] / 2, row[i][j]) - 1);
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("input.txt","r",stdin);
    int t; cin >> t;
    fore(nT,1,t) {
        cin >> r >> c;
        fore(i,1,r) {
            fore(j,1,c) {
                cin >> a[i][j];
            }
        }
        int ans = calc1() + calc2() + calc3() + calc4();
        cout << "Case #" << nT << ": " << ans << '\n';
    }
    return 0;
}