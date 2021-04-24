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
const int N = 5e2 + 5;
const int inf = 1e9;
const int mod = 1e9 + 7;
const double pi = atan(1) * 4.0;
template<typename T, typename U> inline void mini(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> inline void maxi(T &x, U y) { if(x < y) x = y; }

pair<int, int> a[N];
int n, x;

void Solve()
{
    int res = 0;
    cin >> n >> x;
    vector<int> a(n), b(n + 1, inf);
    b[0] = -inf;

    rep(i,n) cin >> a[i];
    rep(i,n)
    {
        int k = upper_bound(b.begin(), b.end(), a[i]) - b.begin();
        b[k] = a[i];
        res = max(res, k);
    }
    set<int> s;
    int j = 1;
    for (int i=0; i<n; i++)
    {
        if (a[i]==b[j])
        {
            ++j;
        }
        else 
        {
            s.insert(a[i]);
        }
    }
    for(int i=1; i<b.size(); i++) cout << b[i] << " ";
    cout << '\n';
    for (auto x: s) cout << x << " ";
    cout << '\n';
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("input.txt","r",stdin);
    int nTest; cin >> nTest;
    while (nTest--) Solve();

    return 0;
}