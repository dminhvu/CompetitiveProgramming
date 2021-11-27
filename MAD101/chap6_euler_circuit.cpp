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
    freopen("input.txt","r",stdin);
    int n, m; cin >> n >> m;
    vector<vector<int> > g(n, vector<int>(n, 0));
    rep(i,m) {
        int u, v; cin >> u >> v;
        --u; --v;
        ++g[u][v];
        ++g[v][u];
    }

    vector<int> deg(n, 0);
    rep(i,n) {
        rep(j,n) {
            deg[i] += g[i][j];
        }
    }

    int first = 0;
    while (first < n && !deg[first]) {
        ++first;
    }
    if (first == n) {
        cout << -1;
        return 0;
    }

    int v1 = -1, v2 = -1;
    bool bad = false;
    rep(i,n) {
        if (deg[i] & 1) {
            if (v1 == -1) {
                v1 = i;
            } else if (v2 == -1) {
                v2 = i;
            } else {
                bad = true;
            }
        }
    }

    if (v1 != -1) {
        ++g[v1][v2], ++g[v2][v1];
    }

    stack<int> st;
    st.push(first);
    vector<int> res;
    while (!st.empty()) {
        int v = st.top();
        int i;
        for (i = 0; i < n; ++i) {
            if (g[v][i]) {
                break;
            }
        }
        if (i == n) {
            res.push_back(v);
            st.pop();
        } else {
            --g[v][i];
            --g[i][v];
            st.push(i);
        }
    }

    if (v1 != -1) {
        for (int i = 0; i + 1 < res.size(); ++i) {
            if ((res[i] == v1 && res[i + 1] == v2) || (res[i] == v2 && res[i + 1] == v1)) {
                vector<int> res2;
                for (int j = i + 1; j < res.size(); ++j)
                    res2.push_back(res[j]);
                for (int j = 1; j <= i; ++j)
                    res2.push_back(res[j]);
                res = res2;
                break;
            }
        }
    }

    rep(i,n) {
        rep(j,n) {
            if (g[i][j])
                bad = true;
        }
    }

    if (bad) {
        cout << -1;
    } else {
        if (res[0] != res[sz(res) - 1]) {
            cout << -1;
        } else {
            for (int x : res)
                cout << x + 1 << " ";
        }
    }
    return 0;
}