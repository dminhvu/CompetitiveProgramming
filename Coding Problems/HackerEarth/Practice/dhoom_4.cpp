#include<bits/stdc++.h>

using namespace std;
const int mod = 1e5;
const int inf = 1e9;

int main() {
	int x, y; cin >> x >> y;
	x %= mod;
	y %= mod;

	int n; cin >> n;

	vector<int> elem(n);
	for (int i = 0; i < n; i++) cin >> elem[i];

	vector<int> dist(mod, inf);
	dist[x] = 0;

	queue<int> q;
	q.push(x);

	while (q.size()) {
		int cur = q.front();
		q.pop();
		for (int i = 0; i < n; i++) {
			int nxt = (1ll * cur * elem[i]) % mod;
			if (dist[nxt] > dist[cur] + 1) {
				dist[nxt] = dist[cur] + 1;
				q.push(nxt);
			}
		}
	}
	cout << (dist[y] == inf ? -1 : dist[y]);
	return 0;
}