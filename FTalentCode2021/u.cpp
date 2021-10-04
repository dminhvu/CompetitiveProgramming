#include <bits/stdc++.h>

using namespace std;
const int N = 2e6 + 5;

int n;
vector<int> adj[N];
int low[N], num[N];
int timer;
stack<int> st;
vector<vector<int> > ans;
map<int, int> mp;

bool cmp(vector<int> a, vector<int> b) {
    return a.size() > b.size() || (a.size() == b.size() && a[0] < b[0]);
}

void visit (int u) {
    low[u] = num[u] = ++timer;
    st.push(u);
    for (int v: adj[u]) {
        if (!num[v]) {
            visit(v);
            low[u] = min(low[u], low[v]);
        } else low[u] = min(low[u], num[v]);
    }
    if (low[u]==num[u]) {
        int v;
        vector<int> tmp;
        do {
            v = st.top();
            tmp.push_back(v);
            low[v] = num[v] = 1e9;
            st.pop();
        } while (v!=u);
        ans.push_back(tmp);
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // freopen("input.txt","r",stdin);
    cin >> n;
    for (int i = 0; i < n; i++) {
        int u, v; cin >> u >> v;
        mp[u] = mp[v] = 1;
        adj[u].push_back(v);
    }
    for (int i = 0; i < n; i++) {
        if (!num[i] && mp[i]) visit(i);
    }
    for (int i = 0; i < ans.size(); i++) sort(ans[i].begin(), ans[i].end());
    cout << ans.size() << '\n';
    sort(ans.begin(), ans.end(), cmp);
    for (int i = 0; i < ans.size(); i++) {
        for (int v: ans[i]) cout << v << " ";
        cout << '\n';
    }
    return 0;
}
