#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < int(n); i++)
#define fore(i,a,b) for (int i = int(a); i <= int(b); i++)
#define ford(i,a,b) for (int i = int(a); i >= int(b); i--)
#define ll int64_t
#define sz(x) int(x.size())

using namespace std;
template<class t, class u> bool maxi(t &a, u b){ if (a < b){ a = b; return 1;} return 0;}
template<class t, class u> bool mini(t &a, u b){ if (a > b){ a = b; return 1;} return 0;}

struct Proposal {
    int tags[5];
};

Proposal p[51];
int n;
ll f[51][16][16][16][16][16];
int minV[5], maxV[5];

ll calc(int i, int state[5]) {
    for (int x = 0; x < 5; ++x) {
        if (state[x] < 0)
            return 0;
    }
    if (i == 0) return f[i][state[0]][state[1]][state[2]][state[3]][state[4]];

    if (f[i][state[0]][state[1]][state[2]][state[3]][state[4]] != -1)
        return f[i][state[0]][state[1]][state[2]][state[3]][state[4]];

    int newState[5];
    for (int x = 0; x < 5; ++x) {
        newState[x] = state[x] - p[i].tags[x];
    }

    ll ans = 0;
    ans = calc(i-1, state) + calc(i-1, newState);
    return f[i][state[0]][state[1]][state[2]][state[3]][state[4]] = ans; 
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int k;
        cin >> k;
        for (int j = 1; j <= k; ++j) {
            string s;
            cin >> s;
            if (s == "dp") p[i].tags[0] = 1;
            if (s == "graph") p[i].tags[1] = 1;
            if (s == "mathgeo") p[i].tags[2] = 1;
            if (s == "ds") p[i].tags[3] = 1;
            if (s == "adhoc") p[i].tags[4] = 1;
        }
    }

    for (int i = 0; i < 5; ++i) {
        cin >> minV[i] >> maxV[i];
    }

    for (int i = 1; i <= n; ++i)
    {
        for (int x0 = 0; x0 <= 15; ++x0)
        {
            for (int x1 = 0; x1 <= 15; ++x1)
            {
                for (int x2 = 0; x2 <= 15; ++x2)
                {
                    for (int x3 = 0; x3 <= 15; ++x3)
                    {
                        for (int x4 = 0; x4 <= 15; ++x4) {
                            f[i][x0][x1][x2][x3][x4] = -1;
                        }
                    }
                }
            }
        }
    }
    f[0][0][0][0][0][0] = 1;

    ll res = 0;
    for (int x0 = minV[0]; x0 <= maxV[0]; ++x0) {
        for (int x1 = minV[1]; x1 <= maxV[1]; ++x1) {
            for (int x2 = minV[2]; x2 <= maxV[2]; ++x2) {
                for (int x3 = minV[3]; x3 <= maxV[3]; ++x3) {
                    for (int x4 = minV[4]; x4 <= maxV[4]; ++x4) {
                        if (x0 + x1 + x2 + x3 + x4 == 0) continue;
                        int state[5] = {x0, x1, x2, x3, x4};
                        res += calc(n, state);
                    }
                }    
            }       
        }    
    }

    // int state[5] = {1, 0, 0, 0, 0};
    // cout << calc(1, state);

    cout << res;

    return 0;
}