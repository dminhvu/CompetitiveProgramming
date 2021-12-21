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
    vector<pii> v;
    int n; cin >> n;
    if (n==3)
    {
        cout << "2\n";
        cout << "3 2\n";
        cout << "3 2\n";
        return;
    }
    if (n==4)
    {
        cout << "3\n";
        cout << "3 4\n";
        cout << "4 2\n";
        cout << "4 2\n";
        return;
    }
    for(int i=3; i<=n-1; i++) v.push_back({i, n});
    int id = n;
    while (n!=1){
        v.push_back({id, 2});
        n = (n/2) + (n%2!=0);
    }
    cout << v.size() << '\n';
    for (auto x: v) cout << x.fi << " " << x.se << '\n';
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //freopen("input.txt","r",stdin);
    int nTest; cin >> nTest;
    while (nTest--) Solve();

    return 0;
}