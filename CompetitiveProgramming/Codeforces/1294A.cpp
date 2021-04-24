#include<bits/stdc++.h>

using namespace std;

int main()
{
    #define ntu
#ifdef ntu
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int nTest; cin >> nTest;
    while (nTest--)
    {   
        int a, b, c, n; cin >> a >> b >> c >> n;
        if ((a + b + c + n) %3 == 0 && (a + b + c + n) / 3 >= max({a, b, c})) cout << "YES\n";
        else cout << "NO\n";
    }   
    return 0;
}