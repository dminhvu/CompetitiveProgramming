#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < int(n); i++)
#define fore(i,a,b) for (int i = int(a); i <= int(b); i++)
#define ford(i,a,b) for (int i = int(a); i >= int(b); i--)
#define ll int64_t
#define sz(x) int(x.size())

using namespace std;
template<class t, class u> bool maxi(t &a, u b){ if (a < b){ a = b; return 1;} return 0;}
template<class t, class u> bool mini(t &a, u b){ if (a > b){ a = b; return 1;} return 0;}

struct Data {
   char c;
   int t, k;
};

int Dijkstra(int** graph, int src, int dst) {
	// TODO: return the length of shortest path from src to dst.
	int n = 0;
	while (&graph[n + 1][0] != NULL) n++;
   n -= 1;
	cout << n << '\n';
	return 1;
}

int main() {
   int init[8][6] = {
	{0, 10, 20, 0, 0, 0},
	{10, 0, 0, 50, 10, 0},
	{20, 0, 0, 20, 33, 0},
	{0, 50, 20, 0, 20, 2},
	{0, 10, 33, 20, 0, 1},
	{0, 0, 0, 2, 1, 0},
   {0, 0, 0, 2, 1, 0},
   {0, 0, 0, 2, 1, 0}, };

   int n = 8;
   int** graph = new int*[n];
   for (int i = 0; i < n; ++i) {
      graph[i] = init[i];
      // for (int j = 0; j < 6; j++) cout << graph[i][j] << " ";
      // cout << '\n';
   }

   cout << Dijkstra(graph, 0, 0);
}