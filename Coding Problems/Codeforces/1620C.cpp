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
    // freopen("input.txt","r",stdin);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int nTest; cin >> nTest;
    while (nTest--) {
        int n, k; cin >> n >> k;
        ll x; cin >> x;
        x -= 1;
        string s; cin >> s;
        vector<ll> v;
        s = ' ' + s + ' ';
        ll cnt = 0;
        fore(i,1,n+1) {
            if (s[i] == '*') {
                cnt += 1;
            } else {
                if (cnt != 0) v.push_back(cnt);
                cnt = 0;
            }
        }
        vector<ll> b;
        ford(i,v.size()-1,0) {
            b.push_back(x % (v[i] * 1ll * k + 1));
            x /= (v[i] * 1ll * k + 1);
        }
        reverse(b.begin(), b.end());
        string ans = "";
        bool used_asterisk = false;
        int j = 0;
        fore(i,1,n) {
            if (s[i] == 'a') {
                ans += s[i];
                used_asterisk = false;
            } else if (!used_asterisk) {
                for(ll l = 0; l < b[j]; l++) ans += "b";
                used_asterisk = true;
                j += 1;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}