#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < int(n); i++)
#define fore(i,a,b) for (int i = int(a); i <= int(b); i++)
#define ford(i,a,b) for (int i = int(a); i >= int(b); i--)
#define ll int64_t
#define sz(x) int(x.size())

using namespace std;
template<class t, class u> bool maxi(t &a, u b){ if (a < b){ a = b; return 1;} return 0;}
template<class t, class u> bool mini(t &a, u b){ if (a > b){ a = b; return 1;} return 0;}
const int MAXN = 1e5 + 5;

vector<int> cnt(MAXN + 5, 0);
int n;

vector<int> generate(vector<vector<int> > a) {
    vector<int> ans;
    vector<int> count2(a.size(), 0);
    fore(i,1,MAXN) {
        if (cnt[i] < n) {
            vector<int> count = count2;
            rep(j,a.size()) {
                rep(k,a[j].size()) {
                    if (a[j][k] == i) {
                        count[j] += 1;
                        if (count[j] > 1) {
                            break;
                        }
                    }
                }
                if (count[j] > 1) break;
            }
            bool flag = true;
            rep(j,a.size()) {
                if (count[j] > 1) {
                    flag = false;
                    break;
                }
            }
            if (!flag) continue;
            ans.push_back(i);
            count2 = count;
            if (ans.size() == n) return ans;
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    vector<vector<int> > a;
    vector<int> tmp;
    fore(i,1,n) {
        tmp.push_back(i);
        cnt[i] += 1;
    }
    cnt[1] += 1;
    a.push_back(tmp);
    fore(i,1,n*(n-1)) {
        if (i == n * (n - 1)) {
            cnt[1] -= 1;
        }
        vector<int> ans = generate(a);
        for (int x: ans) cnt[x] += 1;
        a.push_back(ans);
        // cout<<"asdasdas ";
        // rep(i,ans.size()) cout << ans[i] << " ";
        // cout << '\n';
    }
    // vector<int> verycount(16, 0);
    cout << a.size() << '\n';
    rep(i,a.size()) {
        for (int x: a[i]) {
            cout << x << " ";
            // verycount[x] += 1;
        }
        cout << '\n';
    }
    // fore(i,1,15) cout << verycount[i] << " ";
    return 0;
}