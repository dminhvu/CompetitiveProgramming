#include<bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int nTest; cin >> nTest;
    while(nTest--){
        int x; cin >> x;
        int i = 1;
        while (i * (i + 1) < 2 * x) ++i;
        if (i * (i + 1) == 2 * (x + 1)) ++i;
        cout << i << '\n';
    }
    return 0;
}