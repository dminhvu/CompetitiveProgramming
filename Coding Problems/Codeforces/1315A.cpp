#include<bits/stdc++.h>
#define ntu

using namespace std;

int main()
{
#ifdef ntu
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int nTest; cin >> nTest;
    while (nTest--)
    {
        int a, b, x, y; cin >> a >> b >> x >> y;
        //++a, ++b, ++x, ++y;
        cout << max({x * b, (a - x - 1) * b, y * a, (b - y - 1) * a}) << '\n';
   }   
    return 0;
}