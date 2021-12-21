#include<bits/stdc++.h>
#define rep(i,n) for (int i=0, _n=n; i<_n; i++)
#define FOR(i,a,b) for (int _a=(a), _b=(b), i=_a; _a<=_b?i<=_b:i>=_b; _a<=_b?i++:i--)
#define _mem(a, b) memset(a, (b), sizeof(a))
#define pb push_back
#define fi first
#define se second
#define sz(a) int((a).size())

using namespace std;
typedef long long ll;
typedef int64_t i64;
typedef pair<int, int> pii;
typedef vector<pii> vii;
typedef vector<int> vi;
const int N = 2e5 + 5;
const int inf = 1e9;
const int mod = 1e9 + 7;
const double pi = atan(1) * 4.0;
template<typename T, typename U> inline void mini(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> inline void maxi(T &x, U y) { if(x < y) x = y; }

i64 _pow(i64 x, i64 y)
{
    if (y==0) return 1;
    i64 tmp = _pow(x, y>>1ll);
    if (y&1) return (tmp%mod * tmp%mod * x%mod)%mod;
    return (tmp%mod * tmp%mod)%mod;
}

vector<int> adj[N];
bool vis[N];
vector<pii> e;

int dfs(int u)
{
    int mx = u;
    vis[u] = 1;
    for (int v: adj[u])
    {
        if (!vis[v])
        {
            mx = max(mx, dfs(v));
        }
    }
    return mx;
}

void Solve()
{
    int n, m; cin >> n >> m;
    int ans = 0;
    rep(i,m)
    {
        int u, v; cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    memset(vis,0,sizeof vis);
    for (int i=1; i<=n; i++)
        if (!vis[i]) e.pb({i, dfs(i)});
    sort(e.begin(), e.end());
    int j = 0;
    for (int i=0; i<e.size() - 1; i++)
    {
        while (j<=i) ++j;
        while (j<e.size() && e[j].fi <= e[i].se) ans++, j++;
    }
    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("input.txt","r",stdin);
    int nTest; //cin >> nTest;
    nTest = 1;
    while (nTest--) Solve();

    return 0;
}