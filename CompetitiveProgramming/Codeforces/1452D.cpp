#include<bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("input.txt","r",stdin);
    int nTest; cin >> nTest;
    while (nTest--)
    {
        int x, y; cin >> x >> y;
        int ans = 2 * min(x, y);
        int rem = max(x, y) - min(x, y);
        ans += max(0, rem * 2 - 1);
        cout << ans << '\n';
    }
    return 0;
}