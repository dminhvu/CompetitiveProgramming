#include<bits/stdc++.h>

using namespace std;

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int nTest; cin >> nTest;
    while (nTest--)
    {
        int n; cin >> n;
        cout << max(0, n/2 - (n%2!=0)) << '\n';
    }
    return 0;
}