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
    // freopen("input.txt","r",stdin);
    int t; cin >> t;
    while (t--) {
        string s; cin >> s;
        int n = sz(s);
        s = ' ' + s;
        map<char, int> mp;
        fore(i,1,n) mp[s[i]]++;
        string ans = "";
        fore(i,1,n) {
            if (mp[s[i]] == 1) {
                ans += s[i];
                continue;
            }
            int l = i;
            while (l < n && mp[s[l + 1]] > 1 && s[l + 1] > s[l]) {
                mp[s[l]]--;
                ++l;
            }
            i = l;
            ans += s[l];
        }
        mp.clear();
        string res = "";
        ford(i,sz(ans) - 1,0) {
            mp[ans[i]]++;
            if (mp[ans[i]] == 1) {
                res = ans[i] + res;
            }
        }
        cout << res << '\n';
    }
    return 0;
}