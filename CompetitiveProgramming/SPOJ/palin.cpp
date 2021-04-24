#include<bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("input.txt","r",stdin);
    int nTest; cin >> nTest;
    while (nTest--){
        string s; cin >> s;
        while (s[0]=='0') s.erase(0, 1);
        int n = s.size();
        int i = 0, j = n - 1;
        for(int i=(n - 1)/2; i>=0; i--){
            if (i>0 && s[i - 1]<=s[n - i]){
                s[i]++;
                s[n - i - 1] = s[i];
                
            }
            else{
                s[n - i] = s[i - 1];
            }
            if (s[i]>'9'){
                s[i] = '0';
                s[n - i - 1] = '0';
                if (i==0){
                    s.insert(0, "1");
                    s += "1";
                }
                else{
                    s[i - 1]++;
                    s[n - i] = s[i - 1];
                }
            }
            
        }
        cout << s << '\n';
    }
    return 0;
}