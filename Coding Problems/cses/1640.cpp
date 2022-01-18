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
    int x; cin >> x;
    vector<pair<int, int> > a(n);
    rep(i,n) {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a.begin(), a.end());
    int j = n - 1;
    rep(i,n) {
        if (i >= j) break;
        while (a[i].first + a[j].first > x && i < j) j -= 1;
        if (i != j && a[i].first + a[j].first == x) {
            cout << a[i].second + 1 << " " << a[j].second + 1;
            return 0;
        }
    }
    cout << "IMPOSSIBLE";
    return 0;
}