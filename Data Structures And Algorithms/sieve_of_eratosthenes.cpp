#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < int(n); i++)
#define fore(i,a,b) for (int i = int(a); i <= int(b); i++)
#define ford(i,a,b) for (int i = int(a); i >= int(b); i--)
#define ll int64_t
#define sz(x) int(x.size())

using namespace std;
template<class t, class u> bool maxi(t &a, u b){ if (a < b){ a = b; return 1;} return 0;}
template<class t, class u> bool mini(t &a, u b){ if (a > b){ a = b; return 1;} return 0;}
const int N = 2e5 + 5;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // freopen64("input.txt","r",stdin);
    vector<bool> is_prime(N, true);
    is_prime[1] = false;
    for (int i = 2; i * i < N; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j < N; j+=i) {
                is_prime[j] = false;
            }
        }
    }
    
    int a, b; cin >> a >> b;
    for (int i = a; i <= b; i++) {
        if (is_prime[i]) {
            cout << i << '\n';
        }
    }
    return 0;
}