#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0, _n = n; i < _n; i++)
#define FOR(i, a, b) for (int _a = (a), _b = (b), i = _a; _a <= _b ? i <= _b : i >= _b; _a <= _b ? i++ : i--)
#define _mem(a, b) memset(a, (b), sizeof(a))
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
template <typename T, typename U>
inline void mini(T &x, U y)
{
  if (y < x)
    x = y;
}
template <typename T, typename U>
inline void maxi(T &x, U y)
{
  if (x < y)
    x = y;
}
 
int readInt () {
	bool minus = false;
	int result = 0;
	char ch;
	ch = getchar();
	while (true) {
		if (ch == '-') break;
		if (ch >= '0' && ch <= '9') break;
		ch = getchar();
	}
	if (ch == '-') minus = true; else result = ch-'0';
	while (true) {
		ch = getchar();
		if (ch < '0' || ch > '9') break;
		result = result*10 + (ch - '0');
	}
	if (minus)
		return -result;
	else
		return result;
}
 
vector<int> graph[N];
vector<int> path[N];
int rnk[N];
int parLength[N];
int par[N];
 
void buildTree(int p, int u)
{
  int nonLeaf = 0;
  for (int i = 0; i < graph[u].size(); ++i)
  {
    int v = graph[u][i];
    if (v == p)
      continue;
    buildTree(u, v);
    rnk[u] = max(rnk[u], rnk[v]);
    par[v] = u;
    nonLeaf = 1;
  }
  rnk[u] += nonLeaf;
}
 
void buildParent(int p, int u)
{
  int max1 = -1;
  int max2 = -1;
  for (int i = 0; i < graph[u].size(); ++i)
  {
    int v = graph[u][i];
    if (v == p)
      continue;
    if (rnk[v] > max1)
    {
      max2 = max1;
      max1 = rnk[v];
    }
    else if (rnk[v] > max2)
    {
      max2 = rnk[v];
    }
  }
  for (int i = 0; i < graph[u].size(); ++i)
  {
    int v = graph[u][i];
    if (v == p)
      continue;
    parLength[v] = parLength[u] + 1;
    if (rnk[v] == max1)
    {
      parLength[v] = max(parLength[v], max2 + 2);
    }
    else
    {
      parLength[v] = max(parLength[v], max1 + 2);
    }
  }
  for (int i = 0; i < graph[u].size(); ++i)
  {
    int v = graph[u][i];
    if (v == p)
      continue;
    buildParent(u, v);
  }
}
 
void transform(int u) {
  for (int i = 0; i < graph[u].size(); ++i)
  {
    int v = graph[u][i];
    if (v == par[u])
      continue;
    path[u].push_back(rnk[v]+1);
  }
  path[u].push_back(parLength[u]);
  sort(path[u].begin(), path[u].end());
}
 
int solve(int u, int t)
{
  int left = 0;
  int right = path[u].size() - 1;
  for (int mid = (left+right)/2; left != mid && right != mid; mid = (left + right)/2) {
    if (path[u][mid] <= t) left = mid;
    else right = mid;
  }
  for (int i = right; i >= left; --i) {
    if (path[u][i] <= t) return i;
  }
  return -1;
}
 
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, m;
  n = readInt();
  m = readInt();
  memset(rnk, 0, sizeof rnk);
  memset(parLength, 0, sizeof parLength);
  memset(par, 0, sizeof par);
  for (int i = 1; i < n; ++i)
  {
    int u, v;
    u = readInt();
    v = readInt();
    graph[u].push_back(v);
    graph[v].push_back(u);
  }
 
  buildTree(1, 1);
  buildParent(1, 1);
  for(int i = 1; i <= n; ++i) {
    transform(i);
  }
 
  for (int i = 1; i <= m; ++i)
  {
    int u, t;
    // cin >> u >> t;
    u = readInt();
    t = readInt();
    cout << path[u].size() - (solve(u, t) + 1) << '\n';
  }
}