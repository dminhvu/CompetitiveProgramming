#include<bits/stdc++.h>

using namespace std;

char ch[1005];

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for (int i=1; i<=n; i++) cin >> ch[i];
    int res = 0;
    for (int i=2; i<=n; i++) res += (ch[i]==ch[i - 1]);
    cout << res;
    return 0;
}