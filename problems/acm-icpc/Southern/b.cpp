#include<bits/stdc++.h>

using namespace std;

int main()
{
    //freopen("input.txt","r",stdin);
    int n, c; cin >> n >> c;
    int total_hour = 0, total_minute = 0, total_second = 0;
    for (int i=1; i<=n; i++)
    {
        string s; cin >> s;
        int minute = s[0] - '0';
        total_minute += minute;
        int second = (s[2] - '0') * 10 + s[3] - '0';
        total_second += second;
    }
    total_second -= (n - 1) * c;
    if (total_second<0)
    {
        total_minute -= 1;
        total_second += 60;
    }
    total_minute += total_second/60;
    total_second %= 60;
    total_hour += total_minute/60;
    total_minute %= 60;
    if (total_hour<10) cout << "0" << total_hour << ":";
    else cout << total_hour << ":";
    if (total_minute<10) cout << "0" << total_minute << ":";
    else cout << total_minute << ":";
    if (total_second<10) cout << "0" << total_second;
    else cout << total_second;
    return 0;
}