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
    ll sum = 1ll * n * (n + 1) / 2ll;
    if (sum & 1) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
        queue<int> q1, q2;
        for (int i = 1; i <= n; i++) {
            q1.push(i);
        }
        ll half_sum = sum / 2ll;
        while (sum != half_sum) {
            if (sum > half_sum) {
                int cur = q1.front();
                sum -= cur;
                q2.push(cur);
                q1.pop();
            } else if (sum < half_sum) {
                int cur = q2.front();
                sum += cur;
                q1.push(cur);
                q2.pop();
            }
        }
        cout << q1.size() << '\n';
        while (q1.size()) {
            cout << q1.front() << " ";
            q1.pop();
        }
        cout << '\n';
        cout << q2.size() << '\n';
        while (q2.size()) {
            cout << q2.front() << " ";
            q2.pop();
        }
    }
    return 0;
}