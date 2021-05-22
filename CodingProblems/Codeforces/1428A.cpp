#include<bits/stdc++.h>
//#define ntu

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
        int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
        int res = abs(x1 - x2) + abs(y1 - y2);
        if (x1!=x2 && y1!=y2) res += 2;
        cout << res << '\n';
    }
    return 0;
}