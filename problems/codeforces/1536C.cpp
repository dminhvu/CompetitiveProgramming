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
    // freopen64("input.txt","r",stdin);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int nTest; cin >> nTest;
    while (nTest--) {
        int n; cin >> n;
        string s; cin >> s;
        map<pair<int, int>, int> cnt;
        int cnt_D = 0, cnt_K = 0;
        for(char c: s) {
            if (c == 'D') cnt_D++;
            else cnt_K++;
            int x = cnt_D / __gcd(cnt_D, cnt_K);
            int y = cnt_K / __gcd(cnt_D, cnt_K);
            cout << ++cnt[{x, y}] << " ";
        }
        cout << '\n';
    }
    return 0;
}