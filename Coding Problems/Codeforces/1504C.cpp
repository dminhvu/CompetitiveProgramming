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

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("input.txt","r",stdin);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        string s; cin >> s;
        string a = "";
        rep(i,n/2) a += "()";
        string b = "";
        int cnta = 0, cntb = 0;
        int cntbl = 0;
        ford(i,n-1,0) cntbl += 
        rep(i,n) {
            cnta += (a[i] == '(');
            cnta -= (a[i] == ')');
            if (s[i] == '1') {
                b += a[i];
            } else {
                if (a[i] == '(') {
                    b += ")";
                } else {
                    b += "(";
                }
            }
        }
        bool f = 1;
        rep(i,n) {
            cntb += (b[i] == '(');
            cntb -= (b[i] == ')');
            if (cntb < 0) {
                f = 0;
                break;
            }
        }
        f &= cntb == 0;
        if (f) {
            cout << "YES\n";
            cout << a << '\n' << b << '\n';
        } else cout << "NO\n";
    }
    return 0;
}