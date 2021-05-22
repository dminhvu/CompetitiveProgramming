#include<bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int nTest; cin >> nTest;
    while (nTest--){
        int n; cin >> n;
        if (n==1) cout << "9\n";
        else if (n==2) cout << "98\n";
        else{
            cout << "98";
            int cur = 9;
            for (int i=0; i<n-2; i++){
                cout << cur;
                cur += 1;
                if (cur>9) cur = 0;
            }
            cout << '\n';
        }
    }
    return 0;
}