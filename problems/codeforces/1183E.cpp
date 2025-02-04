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
    freopen64("input.txt","r",stdin);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, k; cin >> n >> k;
    string s; cin >> s;
    queue<string> q;
    set<string> vis;
    q.push(s);
    vis.insert(s);
    int ans = 0;
    while (sz(q) && sz(vis) < k) {
        string cur = q.front();
        q.pop();
        rep(i,sz(cur)) {
            string tmp = cur;
            tmp.erase(i, 1);
            if (!vis.count(tmp) && sz(vis) < k) {
                vis.insert(tmp);
                q.push(tmp);
                ans += sz(s) - sz(tmp);
            }
        }
    }
    cout << (sz(vis) == k ? ans : -1) << '\n';
    return 0;
}