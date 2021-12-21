/*
Task: 
Date: 
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
const int N = 2e5 + 5;
const int inf = 1e9;
const int mod = 1e9 + 7;
const double pi = atan(1) * 4.0;
template<typename T, typename U> inline void mini(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> inline void maxi(T &x, U y) { if(x < y) x = y; }

int dp[N];

set<int> st[26];
string s;
int n;

bool check2(char c, int pos)
{
    bool f1 = (c!=s[pos - 1]);
    bool f2 = (pos<2 || (pos>=2 && c!=s[pos - 2]));
    bool f3 = (pos>n-2 || (pos<=n-2 && c!=s[pos + 2]));
    bool f4 = (pos>n-1 || (pos<=n-1 && c!=s[pos + 1]));
    bool f5 = (c!=s[pos]);
    return f1&&f2&&f3&&f4&&f5;
}

vector<int> v[26];

void Solve()
{
    cin >> s;
    n = sz(s);
    int res = 0;
    s = ' ' + s;
    vector<int> v[26];
    for (int i=1; i<=n; i++)
    {
        v[s[i] - 'a'].push_back(i);
    }
    for (int i=0; i<26; i++)
    {
        if (v[i].size()<=1) continue;
        for (int j=0; j<v[i].size()-1; j++)
        {
            if (j<v[i].size()-2 && v[i][j]==v[i][j + 2] - 2)
            {
                res += 2;
                v[i][j] = inf;
                v[i][j + 2] = inf;
                j++;
            }
            else if (v[i][j]==v[i][j + 1] - 1 || v[i][j]==v[i][j + 1] - 2)
            {
                res++;
                v[i][j] = inf;
                v[i][j + 1] = inf;
            }
        }
    }
    cout << res << '\n';
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("input.txt","r",stdin);
    int nTest; cin >> nTest;
    while (nTest--) Solve();

    return 0;
}