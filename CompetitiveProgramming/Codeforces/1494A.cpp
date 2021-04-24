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

const int dir[8][3] = {{1, 1, 1}, {1, 1, -1}, {1, -1, -1}, {-1, -1, -1}, {1, -1, 1}, {-1, 1, 1}, {-1, -1, 1}, {-1, 1, -1}};

int n;
string s;

bool check(int x) {
    int sum = 0;
    rep(i,n) {
        sum += (s[i] == 'A' ? dir[x][0] : 0);
        sum += (s[i] == 'B' ? dir[x][1] : 0);
        sum += (s[i] == 'C' ? dir[x][2] : 0);
        if (sum < 0) return false;
    }
    return sum == 0;
}

string solve() {
    rep(i,8) if (check(i)) return "YES";
    return "NO";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--) {
        cin >> s;
        n = sz(s);
        cout << solve() << '\n';
    }
    return 0;
}