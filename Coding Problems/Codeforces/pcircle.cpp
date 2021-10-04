#include<bits/stdc++.h>

using namespace std;

int n;
set<vector<int> > ans;
bool mark[20];
int a[20];

bool isPrime(int x)
{
    if (x==1) return 0;
    if (x<=3) return 1;
    for (int i=2; i*i<=x; i++) if (x%i==0) return 0;
    return 1;
}

void solve(int k, vector<int> t)
{
    //if (ans.size()>=10000) return;
    if (k==2*n)
    {
        if (isPrime(a[k] + 1)) ans.insert(t);
        return;
    }
    for (int i=2; i<=2*n; i++)
    {
        if (!mark[i])
        {
            if (isPrime(i + a[k]))
            {
                mark[i] = 1;
                a[k + 1] = i;
                t.push_back(i);
                solve(k + 1, t);
                mark[i] = 0;
                a[k + 1] = 0;
                t.pop_back();
            }
        }
    }
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n;
    a[1] = 1;
    vector<int> v; v.push_back(1);
    solve(1, v);
    cout << ans.size() << '\n';
    int cnt = 0;
    for (auto x: ans)
    {
        cnt++;
        if (cnt>10000) break;
        for (auto y: x) cout << y << " ";
        cout << '\n';
    }
}