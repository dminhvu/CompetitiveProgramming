/*
Task: 1433D
Date: Dec 19, 2020
Author: aLittleLove (Minh Vu)
*/

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
const int N = 5e3 + 5;
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

int a[N];
vector<int> adj[N];
vector<pii> e;
bool vis[N];

void dfs(int u)
{
    vis[u] = 1;
    for (int v: adj[u])
    {
        if (vis[v]) continue;
        e.pb({u, v});
        dfs(v);
    }
}

void Solve()
{
    int n; cin >> n;
    for (int i=1; i<=n; i++) cin >> a[i], adj[i].clear();
    e.clear();
    memset(vis,0,sizeof vis);
    for (int i=1; i<=n; i++)
    {
        for (int j=i+1; j<=n; j++)
        {
            if (a[i]==a[j]) continue;
            adj[i].pb(j);
            adj[j].pb(i);
        }
    }
    for (int i=1; i<=n; i++) if (!vis[i]) dfs(i);
    if (e.size()!=n-1)
    {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    for (pii x: e) cout << x.fi << " " << x.se << '\n';
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("input.txt","r",stdin);
    int nTest; cin >> nTest;
    while (nTest--) Solve();

    return 0;
}