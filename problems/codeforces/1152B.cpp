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
    int x; cin >> x;
    vector<int> ans;
    int count = 0;
    while ((x & (x + 1)) != 0) {
        vector<int> bit;
        int temp = x;
        while (temp) {
            bit.push_back(temp % 2);
            temp /= 2;
        }
        int pos = 0;
        for (int i = 0; i < bit.size(); i++) {
            if (bit[i] == 1) pos = i;
        }
        x ^= ((1 << (pos + 1)) - 1);
        ans.push_back(pos + 1);
        count += 1;
        if ((x & (x + 1)) != 0) {
            x += 1;
            count += 1;
        }
    }
    cout << count << '\n';
    for (int x: ans) cout << x << " ";
    return 0;
}