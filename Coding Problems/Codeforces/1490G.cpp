#include<bits/stdc++.h>
 
using namespace std;
 
int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, d;
    cin >> n >> d;
    string s;
    int ans = 0;
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        cin >> s ;
        for (int j = 1; i <= d; i++) {
            if (s[j] == 1  && s[j + 1] == 1)
            cnt++;
            else cnt = 0;
        }
        if (cnt == d)
        ans++;
    }
    cout << n - ans;
}