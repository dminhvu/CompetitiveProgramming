#include<bits/stdc++.h>
#define ntu

using namespace std;

void Solve()
{
    int n;
    vector<int> v;
    cin >> n;
    for (int i=2; i*i<=n; i++)
    {
        if (n%i==0)
        {
            n /= i;
            v.push_back(i);
            if (v.size()==2 && n!=i) 
            {
                cout << "YES\n";
                for (int x: v) cout << x << " ";
                cout << n << '\n';
                return;
            }
            if (v.size()>2)
            {
                cout << "NO\n";
                return;
            }
        }
    }
    cout << "NO\n";
}

int main()
{
#ifdef ntu
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int nTest; cin >> nTest;
    while (nTest--) Solve();   
    return 0;
}