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

string s;
int n;

bool check1()
{
    int p = 0;
    for (int i=1; i<=n; i++)
    {
        if (s[i]=='(') p++;
        else if (s[i]=='?')
        {
            if (p) p--;
            else p++;
        }
        else p--;
        if (p<0) return 0;
    }
    if (p!=0) return 0;
    return 1;
}

bool check2()
{
    int p = 0;
    for (int i=n; i>=1; i--)
    {
        if (s[i]==')') p++;
        else if (s[i]=='?')
        {
            if (p) p--;
            else p++;
        }
        else p--;
        if (p<0) return 0;
    }
    if (p!=0) return 0;
    return 1;
}

int pref[N], suff[N];

void Solve()
{
    cin >> s;
    n = sz(s);
    s = ' ' + s;
    for (int i=1; i<=n; i++)
    {
        
    }
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("input.txt","r",stdin);
    int nTest; cin >> nTest;
    while (nTest--) Solve();

    return 0;
}