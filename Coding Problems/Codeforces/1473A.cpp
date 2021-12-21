#include<bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int nTest; cin >> nTest;
    while(nTest--){
        int n, d; cin >> n >> d;
        vector<int>a(n);
        for(int i=0; i<n; i++) cin >> a[i];
        sort(a.begin(), a.end());
        bool f = 0;
        if (a[0] + a[1] <= d) f |= 1;
        if (a[n - 1] <= d) f |= 1;
        cout << (f ? "YES\n" : "NO\n");
    }
    return 0;
}