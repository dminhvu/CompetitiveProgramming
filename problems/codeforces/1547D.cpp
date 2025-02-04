#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < int(n); i++)
#define fore(i,a,b) for (int i = int(a); i <= int(b); i++)
#define ford(i,a,b) for (int i = int(a); i >= int(b); i--)
#define ll int64_t
#define sz(x) int(x.size())

using namespace std;
template<class t, class u> bool maxi(t &a, u b){ if (a < b){ a = b; return 1;} return 0;}
template<class t, class u> bool mini(t &a, u b){ if (a > b){ a = b; return 1;} return 0;}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // freopen64("input.txt","r",stdin);
    int nTest; cin >> nTest;
    while (nTest--) {
        int n; cin >> n;
        vector<int> a(n);
        rep(i,n) cin >> a[i];
        vector<int> bit(62, 0);
        vector<int> ans;
        rep(i,n) {
            int cur = a[i];
            int cnt = 0;
            vector<int> tmp(62, 0);
            while (cur) {
                int r = cur % 2;
                tmp[cnt++] |= r;
                cur /= 2;
            }
            int sum = 0;
            for(int j = 0; j < 35; j++) {
                if (tmp[j] < bit[j]) {
                    sum += (1 << j);
                }
            }
            for(int j = 0; j < 35; j++) {
                bit[j] |= tmp[j];
            }
            ans.push_back(sum);
        }
        for(int x: ans) cout << x << " ";
        cout << '\n';
    }
    return 0;
}