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
    int nTest; cin >> nTest;
    while (nTest--) {
        int k, n, m; cin >> k >> n >> m;
        vector<int> a(n), b(m);
        rep(i,n) cin >> a[i];
        rep(i,m) cin >> b[i];
        int i = 0, j = 0;
        bool f = 1;
        vector<int> ans(n + m, 0);
        int cnt = 0;
        while (i < n || j < m) {
            if (i < n && j < m) {
                if (a[i] == 0) {
                    ans[cnt++] = a[i];
                    i++;
                    k++;
                } else if (b[j] == 0) {
                    ans[cnt++] = b[j];
                    j++;
                    k++;
                } else {
                    if (a[i] <= b[j] && a[i] <= k) {
                        ans[cnt++] = a[i];
                        i++;
                    } else if (b[j] <= a[i] && b[j] <= k) {
                        ans[cnt++] = b[j];
                        j++;
                    } else {
                        f = 0;
                        break;
                    }
                }
            } else if (i < n) {
                if (a[i] == 0) {
                    ans[cnt++] = a[i];
                    i++;
                    k++;
                } else if (a[i] <= k) {
                    ans[cnt++] = a[i];
                    i++;
                } else {
                    f = 0;
                    break;
                }
            } else if (j < m) {
                if (b[j] == 0) {
                    ans[cnt++] = b[j];
                    j++;
                    k++;
                } else if (b[j] <= k) {
                    ans[cnt++] = b[j];
                    j++;
                } else {
                    f = 0;
                    break;
                }
            } else {
                break;
            }
        }
        if (f) {
            for(int i = 0; i < n + m; i++) cout << ans[i] << " ";
            cout << '\n';
        } else {
            cout << -1 << '\n';
        }
    }
    return 0;
}