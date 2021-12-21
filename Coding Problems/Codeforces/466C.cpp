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
    freopen("input.txt","r",stdin);
    int n; cin >> n;
    vector<ll> a(n + 1, 0), b(n + 1, 0); 
    ll sum = 0;
    fore(i,1,n) {
        cin >> a[i];
        sum += a[i];
        b[i] = a[i];
    }
    if (sum % 3 != 0) return cout << 0, 0;
    int l = 1, r = 1;
    fore(i,1,n) a[i] += a[i - 1];
    while (l + 1 < n && (a[l] * 3ll != sum || a[l + 1] * 3ll == sum)) l++;
    r = l + 1;
    while (r < n && (a[r] - a[l]) * 3ll != sum) r++;
    if (a[l] * 3ll != sum || (a[r] - a[l]) * 3ll != sum || (a[n] - a[r]) * 3ll != sum) return cout << 0, 0;
    int cntl = 0, cntr = 0, cntm = 0;
    fore(i,2,l-1) cntl += (b[i] == 0);
    fore(i,l,r-1) cntm += (b[i] == 0);
    fore(i,r,n-1) cntr += (b[i] == 0);
    cout << cntl << " " << cntm << " " << cntr << '\n';
    cout << 1ll * (cntl + 1) * (cntr + 1) * (cntm + 1);
    return 0;
}