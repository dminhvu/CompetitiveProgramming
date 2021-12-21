#include<bits/stdc++.h>

using namespace std;

int64_t calc(vector<char> a, vector<char> b) {
    set<char> s(a.begin(), a.end());
    int64_t cnt = 0;
    for (char x: b) {
        if (s.find(x) != s.end()) cnt++;
    }
    return cnt;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("input.txt","r",stdin);
    int nTest; cin >> nTest;
    while (nTest--) {
        int n; cin >> n;
        vector<string> a(n);
        map<string, vector<char> > mp;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            string ed = a[i].substr(1);
            mp[ed].push_back(a[i][0]);
        }
        int64_t ans = 0;
        for (auto x: mp) {
            for (auto y: mp) {
                if (x.first == y.first) continue;
                int64_t cur = calc(x.second, y.second);
                ans += (x.second.size() - cur) * (y.second.size() - cur);
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
/*
3
2
suf mas
3
good game guys
4
hell bell best test
*/
/*
3
2
aba bbb
3
good game guys
4
dtp ctq rts etp
*/