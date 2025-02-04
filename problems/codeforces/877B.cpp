/*
Task: 877B
Date: Dec 21, 2020
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

int prefA[N], prefB[N];

void Solve()
{
    string s; cin >> s;
    int n = sz(s);
    s = ' ' + s;
    for (int i=1; i<=n; i++) 
    {
        prefA[i] = prefA[i - 1] + (s[i]=='a');
        prefB[i] = prefB[i - 1] + (s[i]=='b');
    }
    int res = 0;
    for (int i=1; i<=n; i++)
    {
        for (int j=i; j<=n; j++)
        {
            res = max(res, prefA[i] + prefB[j] - prefB[i] + prefA[n] - prefA[j]);
            res = max(res, prefB[j] + prefA[n] - prefA[j]);
            res = max(res, prefA[i] + prefB[n] - prefB[i]);
            res = max(res, prefB[j]);
            res = max(res, prefA[j]);
        }
    }
    cout << res << '\n';
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