#include<bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int nTest; cin >> nTest;
    while (nTest--){
        string s; cin >> s;
        for(int i=0; i<s.size(); i++){
            if (i%2==0){
                for(char c = 'a'; c<='z'; c++){
                    if (c!=s[i]){
                        s[i] = c;
                        break;
                    }
                }
            }
            else{
                for (char c = 'z'; c>='a'; c--){
                    if (c!=s[i]){
                        s[i] = c;
                        break;
                    }
                }
            }
        }
        cout << s << '\n';
    }
    return 0;
}