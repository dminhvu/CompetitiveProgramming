#include<bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("input.txt","r",stdin);
    int nTest; cin >> nTest;
    while (nTest--){
        int n; cin >> n;
        vector<int> a(n);
        for(int i=0; i<n; i++) cin >> a[i];
        vector<int> v1, v2;
        vector<int> c(n, -1);
        int tot = 0;
        for(int i=1; i<n-1; i++){
            if (a[i]>a[i - 1] && a[i]>a[i + 1]){    
                v1.push_back(i);
                tot++;
                c[i] = 1;
            }
            else if (a[i]<a[i - 1] && a[i]<a[i + 1]){
                v2.push_back(i);
                tot++;
                c[i] = 0;
            }
        }
        int res = tot;
        //cout << tot << '\n';
        for(int i=0; i<n; i++){
            if (c[i]!=-1){
                int dec = -1;
                bool f1 = 0, f2 = 0;
                if (i+1<n && c[i + 1]!=c[i] && c[i + 1]!=-1) f1 = 1;
                if (i>0 && c[i - 1]!=c[i] && c[i - 1]!=-1) f2 = 1;
                if (f1 && f2) dec = -3; 
                else if (f1 || f2) dec = -2;
                if (tot + dec < res){
                    res = tot + dec;
                    //cout << i << " ";
                }
            }
        }
        if (res<0) res = 0;

        cout << res << '\n';
    }
    return 0;
}