#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < int(n); i++)
#define fore(i,a,b) for (int i = int(a); i <= int(b); i++)
#define ford(i,a,b) for (int i = int(a); i >= int(b); i--)
#define ll int64_t
#define sz(x) int(x.size())

using namespace std;
const ll MOD = 1e9+7;
template<class t, class u> bool maxi(t &a, u b){ if (a < b){ a = b; return 1;} return 0;}
template<class t, class u> bool mini(t &a, u b){ if (a > b){ a = b; return 1;} return 0;}

struct Matrix {
    ll data[808][808];
    int n;

    Matrix() {

    }

    Matrix(int N) {
        n = N;
    }

    Matrix multiple(Matrix mat) {
        Matrix res;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int k = 0; k < n; ++k) {
                    res.data[i][j] = (res.data[i][j] + data[i][k] * mat.data[k][j] % MOD)%MOD;
                }
            }
        }
        return res;
    }
};

bool cmp(pair<ll, ll> a, pair<ll, ll> b) {
    return a.second == b.second ? a.first < b.first : a.second < b.second;
}

bool valid(int a) {
    int cnt = 0;
    while(a > 0) {
        if (a % 3 == 0) cnt++;
        else {
            if (cnt % 2 == 1) return false;
            cnt = 0;
        }
        a /= 3;
    }
    return true;
}

bool isCompatible(int a, int b) {
    if (!valid(a)) return false;
    if (!valid(b)) return false;
    for (int i = 1; i <= n; ++i) {
        int x = a % 3;
        int y = b % 3;
        if (x == 1 && y != 2) return false;
        if (x != 1 && y == 2) return false; 
    }
}

bool validWithPillar(int state, vector<ll> pil) {
    for (int i = 1; i <= n; ++i) {
        int x = state % 3;
        if (x == 1 && y != 2) return false;
        if (x != 1 && y == 2) return false; 
    }
}

bool endable(int a) {
    while(a > 0) {
        if (a % 3 == 1) return false;
    }
    return true;
}

Matrix powMatrix(Matrix mat, int k) {
    Matrix res = Matrix(lim);
    Matrix pw = Matrix(lim);
    for (int i = 0; i < lim; ++i) {
        pw.data[i][i] = 1;
    }
    for (; k > 0; k /= 2) {
        if (k % 2 == 1) {
            for (int i = 0; i < lim; ++i) {
                for (int j = 0; j < lim; ++j) {
                    res.data[i][j] += pw.data[i][j];
                }
            }
        }
        pw = pw.multiple(pw);
    }
}

ll n, m, k;
Matrix mat;
pair<ll, ll> pillars[11];
vector<int> colPillars;
vector<vector<ll>> pillarsByCol;
ll f[800];
int lim = 0;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> n >> m >> k;
    for (int i = 0; i < k; ++i) {
        cin >> pillars[i].first;
        cin >> pillars[i].second;
    }

    sort(pillars, pillars+k, cmp);
    for (int i = 0; i < k; ++i) {
        if (colPillars.size() == 0 || pillars[i].second != colPillars[colPillars.size()-1]) {
            colPillars.push_back(pillars[i].second);
            vector<ll> tmp;
            tmp.push_back(pillars[i].first);
            pillarsByCol.push_back(tmp);
        } else {
            pillarsByCol[pillarsByCol.size()-1].push_back(pillars[i].first);
        }
    }

    lim = 1;
    for (int i = 1; i <= n; ++i) {
        lim *= 3;
    }
    f[lim] = 1;
    lim++;
    for (int i = 0; i < lim; ++i) {
        for (int j = 0; j < lim; ++j) {
            if (isCompatible(i, j)) {
                mat.data[i][j] = 1;
            } else {
                mat.data[i][j] = 0;
            }
        }
    }
    mat.n = lim;

    ll preCol = 0;
    for (int i = 0; i < colPillars.size(); ++i) {
        int col = colPillars[i];
        Matrix tempMatrix = powMatrix(mat, col - preCol - 1);
        ll ff[800];
        for (int x = 0; x < lim; ++x) {
            for (int y = 0; y < lim; ++y) {
                ff[x] = f[y] * mat.data[x][y]; 
            }
        }
        for (int x = 0; x < lim; ++x) {
            f[x] = ff[x];
        }
        preCol = col;
        for (int x = 0; x < lim; ++x) {
            for (int y = 0; y < lim; ++y) {
                if (isCompatible(x, y) && validWithPillar(y, pillarsByCol[i])) {
                    ff[y] = (ff[y] + f[x]) % MOD;
                }
            }
        }
        for (int x = 0; x < lim; ++x) {
            f[x] = ff[x];
        }
    }

    ll res = 0;
    for (int i = 0; i < lim; ++i) {
        if (endable(i)) {
            res = (res + f[i]) % MOD;
        }
    }

    cout << res;

    return 0;
}