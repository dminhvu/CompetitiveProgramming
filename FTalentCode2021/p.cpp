#include<bits/stdc++.h>

using namespace std;
const int N = 2e6 + 5;

string s, t;
int z[N];
int n, m;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // freopen("input.txt","r",stdin);
    int p; cin >> p;
    cin >> s >> t;
    n = s.size(); m = t.size();
    z[0] = n;
    t = t + s;
    int l = 0, r = 0;
    for (int i=1; i<n+m; i++) {
        if (i>r) {
            l = r = i;
            while (r<m+n && t[r - l]==t[r]) r++;
            z[i] = r - l;
            --r;
        } else {
            int k = i - l;
            if (z[k]<r-i+1) z[i] = z[k];
            else {
                l = i;
                while (r<m+n && t[r - l]==t[r]) r++;
                z[i] = r - l;
                --r;
            }
        }
    }
    int ans = 0;
    for (int i=m; i<n+m; i++) {
        if (z[i]>=m) ans++;
    }
    if (ans >= p) cout << "Y\n";
    else cout << "N\n";
    return 0;
}
