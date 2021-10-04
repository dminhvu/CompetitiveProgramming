#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < int(n); i++)
#define fore(i,a,b) for (int i = int(a); i <= int(b); i++)
#define ford(i,a,b) for (int i = int(a); i >= int(b); i--)
#define ll int64_t
#define sz(x) int(x.size())

using namespace std;
template<class t, class u> bool maxi(t &a, u b){ if (a < b){ a = b; return 1;} return 0;}
template<class t, class u> bool mini(t &a, u b){ if (a > b){ a = b; return 1;} return 0;}

int x[105];
vector<vector<int> > ans;

void solve(int n, int p = 0) {
    if (n == 0) {
        vector<int> tmp;
        for (int i = 0; i < p; i++) tmp.push_back(x[i]);
        ans.push_back(tmp);
        return;
    }
    for (int i = 1; ; i++) {
        if (n - i < 0) {
            break;
        }
        x[p] = i;
        solve(n - i, p + 1);
        x[p] = 0;
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n = 5;
    solve(n);
    sort(ans.begin(), ans.end());
    for(auto x: ans) {
        for(int y: x) cout << y << " ";
        cout << '\n';
    }
    return 0;
}