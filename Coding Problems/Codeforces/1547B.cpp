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
        string s; cin >> s;
        int left = 0, right = sz(s) - 1;
        bool f = 1;
        for(char c = 'z'; c >= 'a'; c--) {
            if (left > right) break;
            if (c - 'a' >= sz(s)) continue;
            if (s[left] == c) {
                left++;
            } else if (s[right] == c) {
                right--;
            } else {
                f = 0;
                break;
            }
        }
        cout << (f ? "YES\n" : "NO\n");
    }
    return 0;
}