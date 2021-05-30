#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < int(n); i++)
#define fore(i,a,b) for (int i = int(a); i <= int(b); i++)
#define ford(i,a,b) for (int i = int(a); i >= int(b); i--)
#define ll int64_t
#define sz(x) int(x.size())

using namespace std;
template<class t, class u> bool maxi(t &a, u b){ if (a < b){ a = b; return 1;} return 0;}
template<class t, class u> bool mini(t &a, u b){ if (a > b){ a = b; return 1;} return 0;}
const int inf = 1e9;
const int mod = 1e5;

int main() {
	freopen64("input.txt","r",stdin);
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int x, y; cin >> x >> y;
	int n; cin >> n;
	vector<int> a(n);
	rep(i,n) cin >> a[i];
	vector<int> dist(mod, inf);
	dist[x] = 0;

	queue<int> q;
	q.push(x);
	while (q.size()) {
		int cur = q.front();
		q.pop();
		for(int i = 0; i < n; i++) {
			int nxt = (1ll * cur * a[i]) % mod;
			if (dist[nxt] > dist[cur] + 1) {
				dist[nxt] = dist[cur] + 1;
				q.push(nxt);
			}
		}
	}
	cout << (dist[y] == inf ? -1 : dist[y]);
	return 0;
}