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
        int n; cin >> n;
        vector<int> a(n);
        rep(i,n) cin >> a[i];
        sort(a.begin(), a.end());
        int minDist = 2e9;
        int firstId = -1, lastId = -1;
        rep(i,n-1) {
            int curDist = a[i + 1] - a[i];
            if (mini(minDist, curDist)) {
                firstId = i + 1;
                lastId = i;
            }
        }
        if (n == 2) {
            for(int x: a) cout << x << " ";
            cout << '\n';
            continue;
        }
        fore(i,firstId,n-1) cout << a[i] << " ";
        fore(i,0,lastId) cout << a[i] << " ";
        cout << '\n';
    }
    return 0;
}