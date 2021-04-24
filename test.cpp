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

bool cmp(pair<int, char> a, pair<int, char> b) {
    return a.first > b.first;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    char s[2][4] = {{'A', 'A', 'C', 'D'},
                    {'E', 'A', 'G', 'H'}
    };
    vector<int> cnt(26);
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 4; j++) {
            cnt[s[i][j] - 'A']++;
        }
    }
    vector<pair<int, char> > v;
    for(int i = 0; i < 26; i++) {
        v.push_back(make_pair(cnt[i], i + 'A'));
    }
    for(int i = 0; i < 26; i++) {
        cout << (char)(v[i].second) << " " << v[i].first << '\n';
    }
    sort(v.begin(), v.end(), cmp);
    cout << '\n';
    for(int i = 0; i < 26; i++) {
        cout << (char)(v[i].second) << " " << v[i].first << '\n';
    }
    return 0;
}