#include<bits/stdc++.h>

using namespace std;

int64_t a[36];

int64_t POW(int64_t x, int64_t y)
{
    if (y==0) return 1;
    int64_t ans = POW(x, y/2);
    if (y%2) return ans*ans*x;
    return ans*ans;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    //freopen("input.txt","r",stdin);

    a[0] = 2;
    int64_t sum = 0;
    int64_t cnt = 0, p = 0;
    for (int i=1; i<=35; i++)
    {
        if (cnt==2) ++p, cnt = 0;
        cnt++;
        sum += 9ll * POW(10ll, p);
        a[i] = a[i - 1] + sum;
    }
    //for (int i=0; i<=35; i++) cout << a[i] << '\n';
    int nTest; cin >> nTest;
    while (nTest--)
    {
        int x; cin >> x;
        cout << a[x] << '\n';
    }
}