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
    // freopen64("input.txt","r",stdin);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    ll k, x; cin >> k >> x;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    sort(a.begin(), a.end());
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    rep(i,n) {
        if (i == 0) continue;
        if (a[i] - a[i - 1] > x) {
            pq.push(a[i] - a[i - 1]);
        }
    }
    while (sz(pq)) {
        ll cur = pq.top();
        ll cnt = (cur - 1) / x;
        if (k >= cnt) {
            k -= cnt;
            pq.pop();
        } else {
            break;
        }
    }
    cout << sz(pq) + 1 << '\n';
    return 0;
}