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
        int a, b, c1, c2; cin >> a >> b >> c1 >> c2;
        int n; cin >> n;
        vector<pair<int, int> > v(n);
        rep(i,n) {
            cin >> v[i].first >> v[i].second;
        }
        fore(i,0,n-1) {
            fore(j,i+1,n-1) {
                fore(k,j+1,n-1) {
                    set<pair<int, int> > s;
                    
                }
            }
        }
    }
    return 0;
}