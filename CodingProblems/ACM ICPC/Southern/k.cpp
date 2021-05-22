#include<bits/stdc++.h>

using namespace std;
const int N = 1e4 + 5;
const double PI = 3.1415926535;

int t, b;
pair<int, int> a[N];
int res = 0;

int main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    //freopen("input.txt","r",stdin);
    cin >> t >> b;
    for (int i=1; i<=b; i++)
    {
        cin >> a[i].second >> a[i].first;
    }
    sort(a+1,a+b+1);
    for (int i=1; i<=b; i++)
    {
        double total_length = 2.0 * PI * a[i].first * a[i].second;
        //cout << a[i].first << '\n';
        if ((double) t>=total_length)
        {
            res += a[i].second;
            t -= total_length;
        }
        else 
        {
            int l = 0, r = a[i].second;
            int mx = 0;
            while (l<=r)
            {
                int mid = (l + r) >> 1;
                double total_length = 2.0 * PI * a[i].first * mid;
                if (total_length<=(double) t) l = mid + 1, mx = mid;
                else r = mid - 1;
            }
            res += mx;
            t -= total_length;
        }
    }
    cout << res;
}