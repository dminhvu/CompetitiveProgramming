#include<bits/stdc++.h>

using namespace std;

int main()
{
    freopen("input.txt","r",stdin);
    int n; cin >> n;
    string a, b; cin >> a >> b;
    for (int i=0; i<n; i++)
    {
        if (a[i]>='A' && a[i]<='Z')
        {
            cout << char(b[i] + 26 - a[i] - 'A');
        }
        else 
        {
            cout << char((int)(b[i] + 26 - a[i]) - 'a');
        }
    }
}