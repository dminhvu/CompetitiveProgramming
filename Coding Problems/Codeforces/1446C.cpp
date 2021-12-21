#include<bits/stdc++.h>

using namespace std;
const int N = 2e5 + 5;

int n;
int64_t a[N];

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("input.txt","r",stdin);
    cin >> n;
    for (int i=1; i<=n; i++) cin >> a[i];
    for (int i=1; i<=n; i++)
    {
        int64_t mn = 1e9;
        int pos;
        for (int j=1; j<=n; j++)
        {
            if (i==j) continue;
            int64_t cur = (a[i] ^ a[j]);
            if (cur<mn)
            {
                mn = cur;
                pos = j;
            }
        }
        cout << a[i] << " " << a[pos];
        cout << '\n';
    }
    return 0;
}