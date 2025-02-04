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
    int n, q; cin >> n >> q;
    vector<int> pos(50, -1);
    rep(i,n) {
        int c; cin >> c;
        --c;
        if (pos[c] == -1) {
            pos[c] = i;
        }
    }
    while (q--) {
        int c; cin >> c;
        --c;
        cout << pos[c] + 1 << " ";
        rep(i,50) {
            if (pos[i] != -1 && pos[i] < pos[c]) pos[i]++;
        }
        pos[c] = 0;
    }
    return 0;
}