#include<bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int nTest; cin >> nTest;
    while(nTest--){
        string s1, s2; cin >> s1 >> s2;
        int n = s1.size(), m = s2.size();
        bool f = 0;
        string cur = "";
        while (1){
            if (cur.size()>=500) break;
            if (n<m) cur += s2;
            else cur += s1;
            if (cur.size()%n!=0 || cur.size()%m!=0) continue;
            string cur1 = s1;
            string cur2 = s2;
            while (cur1.size()<cur.size()) cur1 += s1;
            while (cur2.size()<cur.size()) cur2 += s2;
            if (cur1==cur && cur2==cur){
                f = 1;
                break;
            }
        }
        if (f) cout << cur << '\n';
        else cout << -1 << '\n';
    }
    return 0;
}