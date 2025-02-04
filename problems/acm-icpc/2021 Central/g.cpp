#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < int(n); i++)
#define fore(i,a,b) for (int i = int(a); i <= int(b); i++)
#define ford(i,a,b) for (int i = int(a); i >= int(b); i--)
#define ll int64_t
#define sz(x) int(x.size())

using namespace std;
template<class t, class u> bool maxi(t &a, u b){ if (a < b){ a = b; return 1;} return 0;}
template<class t, class u> bool mini(t &a, u b){ if (a > b){ a = b; return 1;} return 0;}
const int MAXN = 1000009;
string str;
int lazy[4*MAXN];
int sum[4*MAXN];

void passdown(int id, int l, int r) {
    int mid = (l+r)/2;
    sum[id*2] += (mid-l+1) * lazy[id];
    sum[id*2+1] += (r-mid) * lazy[id];
    lazy[id*2] += lazy[id];
    lazy[id*2+1] += lazy[id];
    lazy[id] = 0;
}

void add(int id, int l, int r, int u, int v, int val) {
    if (l > r) return;
    if (v < l || r < u) return;
    if (u <= l && r <= v) {
        lazy[id] += val;
        sum[id] += (r-l+1) * val;
        return;
    }

    passdown(id, l, r);

    int mid = l + (r - l) / 2;
    add(id*2, l, mid, u, v, val);
    add(id*2+1, mid+1, r, u, v, val);
    sum[id] = sum[id*2] + sum[id*2+1];
}

int getSum(int id, int l, int r, int p) {
    if (l > r) return 0;
    if (p < l || p > r) return 0;
    if (p <= l && r <= p) {
        return sum[id];
    }

    passdown(id, l, r);

    int mid = l + (r - l) / 2;

    return getSum(id*2, l, mid, p) + getSum(id*2+1, mid+1, r, p);
}


int main() {
    // freopen("input.txt","r",stdin);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> str;
    int n; cin >> n;
    for(int i = 1; i <= n; ++i) {
        int val; cin >> val;
        int l; cin >> l;
        int r; cin >> r;
        add(1, 1, str.size(), l, r, val);
    }

    string res = "";

    for (int i = 1; i <= str.size(); ++i) {
        int x = getSum(1, 1, str.size(), i);
        int newChrIndex = ((str[i - 1] - 'A') + x) % 26 + 'A';
        char newChar = (char)newChrIndex;
        res = res + newChar;
    }
    cout << res << '\n';
    return 0;
}