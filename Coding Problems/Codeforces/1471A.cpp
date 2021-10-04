#include<bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int nTest; cin >> nTest;
    while (nTest--){
        int n; int64_t x; cin >> n >> x;
        map<int, int> mp;
        int64_t res = 0, ans = 0;
        for(int i=0; i<n; i++){
            int64_t k; cin >> k;
            res += k/x + (k%x!=0);
            ans += k;
        }
        ans = (ans/x) + (ans%x!=0);
        cout << ans << " " << res << '\n';
    }
    return 0;
}