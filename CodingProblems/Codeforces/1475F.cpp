#include<bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int nTest; cin >> nTest;
    while (nTest--){
        int n; cin >> n;
        string a[n], b[n];
        for(int i=0; i<n; i++){
            cin >> a[i];
        }
        for(int i=0; i<n; i++){
            cin >> b[i];
        }
        for(int i=0; i<n; i++){
            if (i==0){
                for(int j=0; j<n; j++){
                    if (a[i][j]!=b[i][j]){
                        col[j] = 1;
                    }
                }
            }
            else{
                
            }
        }
    }
    return 0;
}