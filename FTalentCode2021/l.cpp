#include<bits/stdc++.h>
#define rep(i,n) for (int i=0, _n=n; i<_n; i++)
#define FOR(i,a,b) for (int _a=(a), _b=(b), i=_a; _a<=_b?i<=_b:i>=_b; _a<=_b?i++:i--)
#define _mem(a, b) memset(a, (b), sizeof(a))
#define sz(a) int((a).size())

using namespace std;
typedef long long ll;
typedef int64_t i64;
typedef pair<int, int> pii;
typedef vector<pii> vii;
typedef vector<int> vi;
const int N = 2e5 + 5;
const int inf = 1e9;
const int mod = 1e9 + 7;
const double pi = atan(1) * 4.0;
template<typename T, typename U> inline void mini(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> inline void maxi(T &x, U y) { if(x < y) x = y; }

bool isPalin(string s) {
    string t = s;
    reverse(t.begin(), t.end());
    return s == t;
}

string sum(string s) {
    int sum = 0;
    for(char c: s) {
        sum += (c - '0');
    }
    string ans = "";
    while (sum) {
        int r = sum % 10;
        ans += char(r + '0');
        sum /= 10;
    }
    if (ans.empty()) ans = "0";
    reverse(ans.begin(), ans.end());
    return ans;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("input.txt","r",stdin);
    int nTest; cin >> nTest;
    while (nTest--) {
        string s; cin >> s;
        while (s.size() && s[0] == '0') s.erase(0, 1);
        if (isPalin(s) && isPalin(sum(s))) cout << "Y\n";
        else cout << "N\n";
    }
    return 0;
}