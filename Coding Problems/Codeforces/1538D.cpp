#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < int(n); i++)
#define fore(i,a,b) for (int i = int(a); i <= int(b); i++)
#define ford(i,a,b) for (int i = int(a); i >= int(b); i--)
#define ll int64_t
#define sz(x) int(x.size())

using namespace std;
template<class t, class u> bool maxi(t &a, u b){ if (a < b){ a = b; return 1;} return 0;}
template<class t, class u> bool mini(t &a, u b){ if (a > b){ a = b; return 1;} return 0;}

string check(int k, int l, int r) {
    if (k >= l && k <= r) {
        return "YES";
    }
    return "NO";
}

int main() {
    // freopen64("input.txt","r",stdin);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int nTest; cin >> nTest;
    while (nTest--) {
        int a, b, k; cin >> a >> b >> k;
        if (k == 1) {
            if (a != b && (a % b == 0 || b % a == 0)) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
            continue;
        }
        vector<pair<int, int> > factor_a, factor_b;
        for(int i = 2; i * i <= a; i++) {
            int cnt = 0;
            if (a % i != 0) continue;
            while (a % i == 0) {
                cnt++;
                a /= i;
            }
            factor_a.push_back({i, cnt});
        }
        if (a > 1) factor_a.push_back({a, 1});
        sort(factor_a.begin(), factor_a.end());
        for(int i = 2; i * i <= b; i++) {
            int cnt = 0;
            if (b % i != 0) continue;
            while (b % i == 0) {
                cnt++;
                b /= i;
            }
            factor_b.push_back({i, cnt});
        }
        if (b > 1) factor_b.push_back({b, 1});
        sort(factor_b.begin(), factor_b.end());
        map<int, int> cnt_a, cnt_b;
        rep(i,sz(factor_a)) {
            cnt_a[factor_a[i].first] = factor_a[i].second;
            // cout << factor_a[i].first << " " << factor_a[i].second << '\n';
        }
        rep(i,sz(factor_b)) {
            cnt_b[factor_b[i].first] = factor_b[i].second;
            // cout << factor_b[i].first << " " << factor_b[i].second << '\n';
        }
        int min_k = 0;
        set<int> s;
        rep(i,sz(factor_a)) s.insert(factor_a[i].first);
        rep(i,sz(factor_b)) s.insert(factor_b[i].first);
        for(auto it = s.begin(); it != s.end(); it++) {
            min_k += cnt_a[*it] != cnt_b[*it];
        }
        // cout << min_k << '\n';
        min_k = min(min_k, 2);
        int max_k = 0;
        rep(i,sz(factor_a)) max_k += factor_a[i].second;
        rep(i,sz(factor_b)) max_k += factor_b[i].second;
        if (k < min_k) {
            cout << "NO\n";
            continue;
        }
        if (k > max_k) {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
        // for(int i = 1; i <= max_k + 5; i++) {
        //     cout << i << " " << check(i, min_k, max_k) << '\n';
        // }
    }
    return 0;
}