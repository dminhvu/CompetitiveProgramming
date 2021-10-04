#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < int(n); i++)
#define fore(i,a,b) for (int i = int(a); i <= int(b); i++)
#define ford(i,a,b) for (int i = int(a); i >= int(b); i--)
#define ll int64_t
#define sz(x) int(x.size())

using namespace std;
template<class t, class u> bool maxi(t &a, u b){ if (a < b){ a = b; return 1;} return 0;}
template<class t, class u> bool mini(t &a, u b){ if (a > b){ a = b; return 1;} return 0;}
const int N = 1e3 + 5;

struct Data {
    int cost, v;
};

map<string, int> mp;
vector<Data> adj[N];
int cost[N];
int ans[N];

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // freopen("input.txt","r",stdin);
    int n; cin >> n;
    rep(i,n) {
        int id; cin >> id;
        --id;
        string s; cin >> s;
        mp[s] = id;
        cin >> cost[mp[s]];
        string t; cin >> t;
        t.erase(0, 1);
        t.erase(t.size() - 1, 1);
        if (t[0] == '-') continue;
        t += ",";
        string cur = "";
        rep(j,t.size()) {
            if (t[j] == ',') {
                adj[mp[cur]].push_back({cost[mp[cur]], mp[s]});
                cur = "";
            } else {
                cur += t[j];
            }
        }
    }
    rep(i,n) {
        if (adj[i].empty()) {
            adj[i].push_back({cost[i], n});
        }
    }

    memset(ans,-1,sizeof ans);
    ans[0] = 0;
    queue<int> q; q.push(0);
    while (q.size()) {
        int u = q.front();
        q.pop();
        for(Data p: adj[u]) {
            int v = p.v;
            int c = p.cost;
            if (ans[v] <= ans[u] + c) {
                ans[v] = ans[u] + c;
                q.push(v);
            }
        }
    }
    cout << ans[n];
    return 0;
}