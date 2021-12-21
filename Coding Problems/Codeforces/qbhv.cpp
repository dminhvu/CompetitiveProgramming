#include<bits/stdc++.h>

using namespace std;

string s;
int n;
set<string> ans;
bool mark[15];

void solve(int pos, string t)
{
    if (pos==n)
    {
        ans.insert(t);
        return;
    }
    for (int i=1; i<=n; i++)
    {
        if (!mark[i])
        {
            mark[i] = 1;
            solve(pos + 1, t + s[i]);
            mark[i] = 0;
        }
    }
}
int main()
{
    freopen("input.txt","r",stdin);
    cin >> s;
    n = s.size();
    s = ' ' + s;
    solve(0, "");
    cout << ans.size() << '\n';
    for (auto x: ans) cout << x << '\n';
    return 0;
}