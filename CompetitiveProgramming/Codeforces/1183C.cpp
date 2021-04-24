/*
Task: 1183C
Date: Dec 25, 2020
Author: aLittleLove (Minh Vu)
*/

#include<bits/stdc++.h>

using namespace std;

void Solve()
{
    int64_t k, n, a, b; cin >> k >> n >> a >> b;
    int64_t l = 0, r = n, ans = -1;
    while (l<=r)
    {
        int64_t mid = (l + r) >> 1ll;
        if (k - mid * a - (n - mid) * b > 0)
        {
            ans = mid;
            l = mid + 1;
        }
        else r = mid - 1;
    }
    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("input.txt","r",stdin);
    int nTest; cin >> nTest;
    while (nTest--) Solve();
    return 0;
}