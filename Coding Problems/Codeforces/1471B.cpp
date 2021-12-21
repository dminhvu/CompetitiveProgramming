#include<bits/stdc++.h>
#define i64 int64_t

using namespace std;
const i64 mod = 1e18 + 7;

i64 _pow(i64 x, i64 y){
    if (y==0) return 1;
    i64 tmp = _pow(x, y>>1ll);
    if (y&1) return (tmp%mod * tmp%mod * x%mod)%mod;
    return (tmp%mod * tmp%mod)%mod;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int nTest; cin >> nTest;
    while (nTest--){
        int n, x; cin >> n >> x;
        vector<int> a(n), b(n, 0);
        bool f = 0;
        int64_t sum = 0;
        queue<pair<int, int> > q;
        for(int i=0; i<n; i++){
            cin >> a[i];
            q.push({a[i], 0});
        }
        while (q.size()){
            int fi = q.front().first;
            int se = q.front().second;
            if (fi==-1 && se==-1) break;
            q.pop();
            sum += 1ll * fi * _pow(x, se);
            if (fi%x==0) q.push({fi/x, se + 1});
            else q.push({-1, -1});
        }
        cout << sum << '\n';
    }
    return 0;
}