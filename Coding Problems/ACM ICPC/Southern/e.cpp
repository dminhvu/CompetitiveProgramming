#include<bits/stdc++.h>

using namespace std;
const int N = 1e5 + 5;

int n;
int a[N];

int main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    //freopen("input.txt","r",stdin);
    cin >> n;
    for (int i=1; i<=n; i++) cin >> a[i];
    do 
    {
        bool f = 1;
        for (int i=2; i<n; i++)
        {
            if (a[i]<a[i - 1] && a[i]>a[i + 1]) f = 0;
            if (a[i]>a[i - 1] && a[i]<a[i + 1]) f = 0;
            if (!f) break;
        }
        if (f) break;
    } while (next_permutation(a+1,a+n+1));
    for (int i=1; i<=n; i++) cout << a[i] << " ";
}