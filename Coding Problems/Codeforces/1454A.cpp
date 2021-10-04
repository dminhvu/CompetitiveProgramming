#include<bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int nTest; cin >> nTest;
    while (nTest--)
    {
        int n; cin >> n;
        if (n%2==0) for (int i=n; i>=1; i--) cout << i << " ";
        else 
        {
            for (int i=n; i>n/2+1; i--) cout << i << " ";
            for (int i=1; i<=n/2+1; i++) cout << i << " ";
        }
        cout << '\n';
    }
    return 0;
}