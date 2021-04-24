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

int n, m, k;
vector<int> x, y;
vector<vector<int> > adj, node;
int Time = 0, nodeCount = 0;
map<int, int> in, out;

void dfs(int u) {
    cout << u << '\n';
    in[nodeCount] = ++Time;
    node[u].pb(++nodeCount);
    if (adj[u].size()) dfs(adj[u][0]);
    if (adj[u].size() == 2) dfs(adj[u][1]);
    out[nodeCount] = ++Time;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("input.txt","r",stdin);
    cin >> n >> m >> k;
    x.resize(n + 1);
    y.resize(n + 1);
    adj.resize(n + 1);
    node.resize(n + 1);
    rep(i,n) {
        cin >> x[i + 1] >> y[i + 1];
    }
    rep(i,m) {
        int u, v; cin >> u >> v;
        if (x[u] <= x[v] && y[u] >= y[v]) adj[u].pb(v);
        else adj[v].pb(u);
    }
    dfs(1);
    rep(i,k) {
        int u, v; cin >> u >> v;
        bool f = 0;
        rep(z,sz(node[u])) {
            rep(t,sz(node[v])) {
                f |= (in[node[u][z]] <= in[node[v][t]] && out[node[u][z]] >= out[node[v][t]]);
                f |= (in[node[u][z]] >= in[node[v][t]] && out[node[u][z]] <= out[node[v][t]]);
            }
        }
        cout << (f ? "TAK\n" : "NIE\n");
    }
    cout << in[node[1][0]];
    return 0;
}