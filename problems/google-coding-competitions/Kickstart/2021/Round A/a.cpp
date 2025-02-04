#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < int(n); i++)
#define fore(i,a,b) for (int i = int(a); i <= int(b); i++)
#define ford(i,a,b) for (int i = int(a); i >= int(b); i--)
#define ll int64_t
#define pb push_back
#define fi first
#define se second
#define sz(x) int(x.size())

using namespace std;
template<class t, class u> bool maxi(t &a, u b){ if (a < b){ a = b; return 1;} return 0;}
template<class t, class u> bool mini(t &a, u b){ if (a > b){ a = b; return 1;} return 0;}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    fore(nT,1,t) {
        int n, k;
        string s;
        cin >> n >> k >> s;
        s = ' ' + s;
        int initScore = 0;
        fore(i,1,n/2) {
            initScore += (s[i] != s[n - i + 1]);
        }
        int ans = 0;
        fore(i,1,n/2) {
            if (s[i] == s[n - i + 1]) {
                if (initScore < k) {
                    ans++;
                    initScore++;
                }
            } else {
                if (initScore > k) {
                    ans++;
                    initScore--;
                }
            }
        }
        cout << "Case #" << nT << ": " << ans << '\n';
    }
    return 0;
}