#include<bits/stdc++.h>

using namespace std;
const long double PI = 3.1415926535;

int32_t main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    //freopen("input.txt","r",stdin);
    int nTest; cin >> nTest;
    while (nTest--)
    {
        int64_t v; cin >> v;
        long double h = cbrt(((long double)(v)/PI)*4.0);
        long double r = h/2.0;
        long double ans = 2.0*PI*r*r + 2.0*PI*r*h;
        cout << fixed << setprecision(6) << ans << '\n';
    }
}