/*
Task: 821D
Date: Dec 25, 2020
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
const int N = 1e4 + 5;
const int inf = 1e9;
const int mod = 1e9 + 7;
const double pi = atan(1) * 4.0;
template<typename T, typename U> inline void mini(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> inline void maxi(T &x, U y) { if(x < y) x = y; }

vector<vector<int> > dist;
int n, m, k;
vector<vector<bool> > lit;

struct Data
{
    int x, y, d, row, col;
    bool operator < (const Data &oth) const 
    {
        return d>oth.d;
    }
};

void Solve()
{
    cin >> n >> m >> k;
    dist.resize(n + 1, vector<int>(m + 1, inf));
    lit.resize(n + 1, vector<bool>(m + 1, 0));
    rep(i,k)
    {
        int x, y; cin >> x >> y;
        lit[x][y] = 1;
    }
    dist[1][1] = 0;
    priority_queue<Data> pq;
    pq.push({1, 1, 0, 0, 0});
    while (pq.size())
    {
        Data cur = pq.top(); pq.pop();
        int x = cur.x, y = cur.y;
        int d = cur.d;
        int row = cur.row, col = cur.col;
        if (x==n && y==m)
        {
            cout << d;
            return;
        }
        if (x<n)
        {
            if (lit[x + 1][y] && dist[x + 1][y] > dist[x][y])
            {
                dist[x + 1][y] = dist[x][y];
                pq.push({x + 1, y, d, row, col});
            }
            else if (!lit[x + 1][y])
            {
                if (col==y && dist[x + 1][y] > dist[x][y])
                {
                    dist[x + 1][y] = dist[x][y];
                    pq.push({x + 1, y, d, 0, col});
                }
                if (lit[x][y] && dist[x + 1][y] > dist[x][y] + 1)
                {
                    dist[x + 1][y] = dist[x][y] + 1;
                    pq.push({x + 1, y, d + 1, 0, y});
                    pq.push({x + 1, y, d + 1, x + 1, 0});
                }
            }
        }
        if (y<m)
        {
            if (lit[x][y + 1] && dist[x][y + 1] > dist[x][y])
            {
                dist[x][y + 1] = dist[x][y];
                pq.push({x, y + 1, d, row, col});
            }
            else if (!lit[x][y + 1])
            {
                if (row==x && dist[x][y + 1] > dist[x][y])
                {
                    dist[x][y + 1] = dist[x][y];
                    pq.push({x, y + 1, d, row, 0});
                }
                if (lit[x][y] && dist[x][y + 1] > dist[x][y] + 1)
                {
                    dist[x][y + 1] = dist[x][y] + 1;
                    pq.push({x, y + 1, d + 1, x, 0});
                    pq.push({x, y + 1, d + 1, 0, y + 1});
                }
            }
        }
        if (x>1)
        {
            if (lit[x - 1][y] && dist[x - 1][y] > dist[x][y])
            {
                dist[x - 1][y] = dist[x][y];
                pq.push({x - 1, y, d, row, col});
            }
            else if (!lit[x - 1][y])
            {
                if (col==y && dist[x - 1][y] > dist[x][y])
                {
                    dist[x - 1][y] = dist[x][y];
                    pq.push({x - 1, y, d, 0, col});
                }
                if (lit[x][y] && dist[x - 1][y] > dist[x][y] + 1)
                {
                    dist[x - 1][y] = dist[x][y] + 1;
                    pq.push({x - 1, y, d + 1, 0, y});
                    pq.push({x - 1, y, d + 1, x - 1, 0});
                }
            }
        }
        if (y>1)
        {
            if (lit[x][y - 1] && dist[x][y - 1] > dist[x][y])
            {
                dist[x][y - 1] = dist[x][y];
                pq.push({x, y - 1, d, row, col});
            }
            else if (!lit[x][y - 1])
            {
                if (row==x && dist[x][y - 1] > dist[x][y])
                {
                    dist[x][y - 1] = dist[x][y];
                    pq.push({x, y - 1, d, row, 0});
                }
                if (lit[x][y] && dist[x][y - 1] > dist[x][y] + 1)
                {
                    dist[x][y - 1] = dist[x][y] + 1;
                    pq.push({x, y - 1, d + 1, x, 0});
                    pq.push({x, y - 1, d + 1, 0, y - 1});
                }
            }
        }
    }
    cout << -1;
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