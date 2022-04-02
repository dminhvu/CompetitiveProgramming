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
    int n, m; cin >> n >> m;
    vector<vector<int> > adj(n);
    rep(i,m) {
        int k; cin >> k;
        vector<int> a(k);
        rep(j,k) {
            cin >> a[j];
            --a[j];
        }
        fore(j,1,k-1) {
            adj[a[j]].push_back(a[j - 1]);
            adj[a[j - 1]].push_back(a[j]);
        }
    }
    vector<int> component_size;
    vector<int> component(n, 0);
    int count_components = 0;
    
    rep(i,n) {
        if (!component[i]) {
            queue<int> q;
            q.push(i);
            component[i] = ++count_components;
            int count_size = 0;
            while (q.size()) {
                int u = q.front();
                q.pop();
                count_size += 1;
                for (int v: adj[u]) {
                    if (component[v]) {
                        continue;
                    }
                    component[v] = count_components;
                    q.push(v);
                }
            }
            component_size.push_back(count_size);
        }
    }
    rep(i,n) cout << component_size[component[i] - 1] << " ";
    return 0;
}