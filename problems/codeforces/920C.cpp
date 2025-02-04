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
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    vector<pair<int, int> > pos;
    string s; cin >> s;
    s += '0';
    int j = 0;
    rep(i,n) {
        if (s[i] == '1') {
            continue;
        } else {
            if (i != j) {
                pos.push_back({j, i});
            }
            j = i + 1;
        }
    }
    for (pair<int, int> p: pos) {
        sort(a.begin() + p.first, a.begin() + p.second + 1);
    }
    if (is_sorted(a.begin(), a.end())) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
    return 0;
}