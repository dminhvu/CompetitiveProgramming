#include<bits/stdc++.h>

using namespace std;
const int N = 2e5 + 5;

int n;
vector<int> a, b;
map<int, int> bit;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("input.txt","r",stdin);
    cin >> n;
    a.resize(n + 1);
    b.resize(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    multiset<int> ms;
    int64_t ans = 0;
    for (int i = n; i >= 1; i--) {
        ans += calc(a[i] - b[i] - 1);
        ans += 1ll * (k - ms.begin());
        ms.insert(b[i] - a[i]);
    }
    cout << ans << '\n';
    return 0;
}