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
const int N = 2e5 + 5;
const int mod = 1e9 + 7;
const int M = 1e6 + 5;

ll inv[N];
map<ll, ll> cnt;
vector<int> prime;
map<ll, ll> incre;
map<ll, ll> curLevel;

void generatePrime() {
    vector<bool> isPrime(M, 1);
    isPrime[0] = isPrime[1] = 0;
    for (int i = 2; i * i <= M; i++) {
        if (isPrime[i]) {
            for (int j = 2; j * i <= M; j++) {
                isPrime[j * i] = 0;
            }
        }
    }
    fore(i,1,M-1) if (isPrime[i]) prime.push_back(i);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("input.txt","r",stdin);
    generatePrime();
    inv[1] = 1;
    for (int i = 2; i < N ; i++) {
        inv[i] = mod - (mod / i) * inv[mod % i] % mod;
    }

    int n, q; cin >> n >> q;
    vector<ll> a(n);
    int cnt1 = 0;
    vector<multiset<int>> s(n);
    rep(i,n) {
        cin >> a[i];
        if (a[i] == 1) cnt1++;
        int x = a[i];
        ll cntP = 0;
        rep(j,sz(prime)) {
            if (prime[j] * prime[j] > x) break;
            cntP = 0;
            if (x % prime[j] == 0) {
                cnt[prime[j]]++;
                s[i].insert(prime[j]);
                incre[prime[j]]++;
                while (x % prime[j] == 0) {
                    x /= prime[j];
                    ++cntP;
                }
                if (curLevel.count(x) == 0) {
                    curLevel[x] = cntP;
                } else curLevel[x] = min(curLevel[x], cntP);
            }
        }
        if (x > 1) {
            if (s[i].find(x) == s[i].end()) {
                cnt[x]++;
                incre[x]++;
            } else {
                cntP++;
                curLevel[x] = min(curLevel[x], cntP);
            }
            s[i].insert(x);
        }
    }
    ll g = 1;
    for (auto [x, y]: cnt) {
        cout << curLevel[x] << ' ';
        if (y < n) continue;
        g = (g % mod * x % mod) % mod;
    }
    // cout << g << '\n';
    vector<set<pair<int, int> > > pos(M);
    while (q--) {
        ll x, y; cin >> x >> y;
        --x;
        if (a[x] == 1 && y != 1) cnt1--;
        a[x] = max(a[x], y);
        rep(j,sz(prime)) {
            if (prime[j] * prime[j] > y) break;
            if (y % prime[j] == 0) {
                if (s[x].find(prime[j]) == s[x].end()) {
                    cnt[prime[j]]++;
                }
                pos[prime[j]].erase({s[x].count(prime[j]), x});
                s[x].insert(prime[j]);
                pos[prime[j]].insert({s[x].count(prime[j]), x});
                if (pos[prime[j]].begin()->first == curLevel[prime[j]] + 1 && pos[prime[j]].begin()->first == (--pos[prime[j]].end())->first && pos[prime[j]].size() == n) {
                    g = (g % mod * prime[j] % mod) % mod;
                    curLevel[prime[j]]++;
                }
                while (y % prime[j] == 0) {
                    y /= prime[j];
                }
            }
        }
        if (y > 1) {
            s[x].insert(y);
            cnt[y]++;
        }
        if (cnt1) {
            cout << 1 << '\n';
        } else {
            cout << g << '\n';
        }
    }
    return 0;
}