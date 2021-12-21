#include<bits/stdc++.h>
#define int long long

using namespace std;

int32_t main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    //freopen("input.txt","r",stdin);
    int nTest; cin >> nTest;
    while (nTest--)
    {
        int n, k; cin >> n >> k;
        int l = 0, r = n;
        int res = 0;
        while (l<=r)
        {
            int mid = (l + r) >> 1;
            int sum = ((mid + 1)*mid)/2;
            if (sum<=k)
            {
                res = mid;
                l = mid + 1;
            }
            else r = mid - 1;
        }
        cout << res << '\n';
    }
}