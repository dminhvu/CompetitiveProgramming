#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < int(n); i++)
#define fore(i,a,b) for (int i = int(a); i <= int(b); i++)
#define ford(i,a,b) for (int i = int(a); i >= int(b); i--)
#define ll int64_t
#define sz(x) int(x.size())

using namespace std;
template<class t, class u> bool maxi(t &a, u b){ if (a < b){ a = b; return 1;} return 0;}
template<class t, class u> bool mini(t &a, u b){ if (a > b){ a = b; return 1;} return 0;}

int binary_search(vector<pair<int, int> > a, int pos, int x) {
    int n = a.size();
    int l = pos, r = n - 1;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (a[mid].first < x) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return (l >= n ? -1 : l);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<pair<int, int> > a(n);
    rep(i,n) {
        cin >> a[i].first >> a[i].second;
    }
    sort(a.begin(), a.end(), [](const auto& a, const auto& b) {
        return a.second < b.second;
    });
    int ans = 1;
    int end = a[0].second;
    rep(i,n) {
        if (a[i].first >= end) {
            end = a[i].second;
            ans += 1;
        }
    }
    cout << ans;
    return 0;
}