/*
Task: 
Date: 
Author: aLittleLove (Minh Vu)
*/

#define FOR(i,a,b) for (int _a=(a), _b=(b), i=_a; _a<=_b?i<=_b:i>=_b; _a<=_b?i++:i--)

#include<bits/stdc++.h>

using namespace std;
const int N = 3e4 + 5;
const int inf = 1e9;

int n;
int a[N], pref[N], suff[N];

void Solve()
{
    cin >> n;
    FOR(i,1,n) cin >> a[i];
    pref[0] = suff[n + 1] = inf;
    FOR(i,1,n) pref[i] = min(pref[i - 1], a[i]);
    FOR(i,n,1) suff[i] = min(suff[i + 1], a[i]);
    bool ok = 1;
    FOR(i,1,n) ok &= (pref[i - 1] + suff[i + 1] >= a[i]);
    cout << (ok ? "YES\n" : "NO\n");
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("input.txt","r",stdin);
    int nTest; cin >> nTest;
    while (nTest--) Solve();
    return 0;
}