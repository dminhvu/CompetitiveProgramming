#include<bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int nTest; nTest = 1;
    while (nTest--){
        set<int> s;
        int n, k; cin >> n >> k;
        vector<int> a(n + 1), b(n + 1);
        for(int i=1; i<=k; i++){
            a[i] = i;
            s.insert(a[i]);
        }
        for(int i=k+1; i<=n; i++){
            a[i] = k + (k - i);
        }
        int inv = ((n - k) * (n - k + 1)) / 2;
        int curinv = 0;
        for(int i=1; i<=k; i++){
            auto it = s.rbegin();
            while (1){
                int x = *it;
                int cnt = 1;
                int nxtpos = k + (n - i);
                int total = 0;
                if (nxtpos <= n) total += (nxtpos - i - 1 - cnt + 1) + (nxtpos - nxtpos - cnt + 1) * 2;
                else total = (n - x - cnt) * (k - i - cnt + 1) / 2;
                cout << total << '\n';
                if (curinv + total <= inv){
                    b[i] = x;
                    if (nxtpos <= n) b[nxtpos] = x;
                    s.erase(x);
                    if (s.empty()) break;
                    it = s.rbegin();
                    curinv += total;
                    break;
                }
                ++it;
                ++cnt;
                if (it==s.rend() || s.empty()) break;
            }
        }
        for(int i=1; i<=n; i++) cout << b[i] << " ";
    }
    return 0;
}