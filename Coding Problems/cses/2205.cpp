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
    int n; cin >> n;
    queue<string> q;
    string start = "";
    rep(i,n) start += "0";
    map<string, int> vis;
    vis[start] = 1;
    q.push(start);
    while (q.size()) {
        string cur = q.front();
        cout << cur << '\n';
        q.pop();
        rep(i,n) {
            string tmp = cur;
            tmp[i] = (1 - (tmp[i] - '0') + '0');
            if (!vis[tmp]) {
                q.push(tmp);
                vis[tmp] = 1;
                break;
            }
        }
    }
    return 0;
}