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

void Solve()
{
    int n; cin >> n;
    vector<pii> v(n + 1);
    v[0] = {0, 1};
    map<int, int> mp;
    FOR(i,1,n) cin >> v[i].fi, v[i].se = 0;
    int res = 0;
    FOR(i,1,n) FOR(j,1,i-1)
    {
        int s = v[i].fi * (v[j].se - v[0].se);
        s += v[j].fi * (v[0].se - v[i].se);
        s += v[0].fi * (v[i].se - v[j].se);
        s = abs(s);
        mp[s]++;
        if (mp[s]==1) res++;
    }
    cout << res - 1 << '\n';
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("input.txt","r",stdin);
    int nTest; cin >> nTest;
    while (nTest--) Solve();

    return 0;
}