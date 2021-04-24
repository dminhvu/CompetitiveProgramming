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
    freopen("input.txt","r",stdin);
    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        set<int> s;
        map<int, int> mp;
        rep(i,n) {
            int x; cin >> x;
            s.insert(x);
            mp[x] = 1;
        }
        int cur = 0;
        rep(i,min(k,n)) {
            while (mp[cur] == 1) cur++;
            if (cur > *(--s.end())) break;
            int nxt = (cur + 1 + *(--s.end())) / 2;
            if (nxt != cur) {
                s.insert(nxt);
                k = 0;
                break;
            }
            ++cur;
        }
        cout << k + sz(s) << '\n';
    }
    return 0;
}