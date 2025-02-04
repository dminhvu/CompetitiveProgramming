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
    string s; cin >> s;
    int n = s.size();
    vector<int> cnt(26, 0);
    rep(i,n) {
        cnt[s[i] - 'A'] += 1;
    }
    bool has_odd = false;
    rep(i,26) {
        if (cnt[i] & 1) {
            if (has_odd) {
                cout << "NO SOLUTION";
                return 0;
            } else {
                has_odd = true;
            }
        }
    }
    
    rep(i,26) {
        if (cnt[i] % 2 == 0) {
            rep(j,cnt[i]/2) {
                cout << (char)(i + 'A');
            }
        }
    }
    rep(i,26) {
        if (cnt[i] & 1) {
            rep(j,cnt[i]) cout << (char)(i + 'A');
        }
    }

    ford(i,25,0) {
        if (cnt[i] % 2 == 0) {
            rep(j,cnt[i]/2) {
                cout << (char)(i + 'A');
            }
        }
    }
    return 0;
}