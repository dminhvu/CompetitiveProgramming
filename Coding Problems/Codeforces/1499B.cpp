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
    while (t--) {
        string s; cin >> s;
        int n = sz(s);
        vector<vector<int> > pos(2);
        rep(i,n) pos[s[i] - '0'].push_back(i);
        int last = -2;
        int lastOnePos = -2;
        rep(i,sz(pos[1])) {
            if (i == 0) continue;
            if (pos[1][i] == pos[1][i - 1] + 1) {
                lastOnePos = pos[1][i];
                break;
            }
        }
        if (lastOnePos == -2) {
            cout << "YES\n";
            continue;
        }
        last = -2;
        bool f = 1;
        rep(i,sz(pos[0])) {
            if (pos[0][i] < lastOnePos) continue;
            if (pos[0][i] == last + 1) {
                f = 0;
                break;
            } else {
                last = pos[0][i];
            }
        }
        cout << (f ? "YES\n" : "NO\n");
    }
    return 0;
}