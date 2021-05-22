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

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("input.txt","r",stdin);
    int n; cin >> n;
    vector<vector<int> > adj(n + 1);
    int cnt = 0;
    map<string, int> mp;
    rep(i,n) {
        string x, y, z; cin >> x >> y >> z;
        transform(x.begin(), x.end(), x.begin(), [](unsigned char c) { return tolower(c);});
        transform(z.begin(), z.end(), z.begin(), [](unsigned char c) { return tolower(c);});
        if (mp[x] == 0) mp[x] = ++cnt;
        if (mp[z] == 0) mp[z] = ++cnt;
        adj[mp[z] - 1].push_back(mp[x] - 1);
    }
    function<int(int,int)> dfs = [&] (int u, int p) {
        int maxHeight = 0;
        // cout << u << " ";
        for(int v: adj[u]) {
            if (v == p) continue;
            maxHeight = max(maxHeight, dfs(v, u));
        }
        return 1 + maxHeight;
    };
    cout << dfs(mp["polycarp"] - 1, -1);
    return 0;
}