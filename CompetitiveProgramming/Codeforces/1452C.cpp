#include<bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //freopen("input.txt","r",stdin);
    int nTest; cin >> nTest;
    while (nTest--)
    {
        string s; cin >> s;
        vector<int> v1, v2;
        bool f = 1;
        int ans = 0;
        for (int i=0; i<s.size(); i++)
        {
            if (s[i]=='(')
            {
                v1.push_back(i);
            }
            else if (s[i]==')')
            {
                if (v1.empty()) continue;
                v1.pop_back();
                ans++;
            }
            else if (s[i]=='[')
            {
                v2.push_back(i);
            }
            else if (s[i]==']')
            {
                if (v2.empty()) continue;
                v2.pop_back();
                ans++;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}