#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < int(n); i++)
#define fore(i,a,b) for (int i = int(a); i <= int(b); i++)
#define ford(i,a,b) for (int i = int(a); i >= int(b); i--)
#define ll int64_t
#define sz(x) int(x.size())
#define OJ

using namespace std;
template<class t, class u> bool maxi(t &a, u b){ if (a < b){ a = b; return 1;} return 0;}
template<class t, class u> bool mini(t &a, u b){ if (a > b){ a = b; return 1;} return 0;}

struct Rect {
    int x1, y1, x2, y2;
};

int longest_edge(Rect a, Rect b) {
    int ans1 = max(0, (max(a.x1, b.x1) - min(a.x2, b.x2)));
    int ans2 = max(0, (max(a.y2, b.y2) - min(a.y1, b.y1)));
    int ans3 = max(0, (max(a.x2, b.x2) - min(a.x1, b.x1)));
    int ans4 = max(0, (max(a.y1, b.y1) - min(a.y2, b.y2)));
    return max({ans1, ans2, ans3, ans4});
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    #ifdef OJ
    freopen("square.in","r",stdin);
    freopen("square.out","w",stdout);
    #endif
    // freopen("input.txt","r",stdin);
    Rect a, b;
    cin >> a.x1 >> a.y1 >> a.x2 >> a.y2;
    cin >> b.x1 >> b.y1 >> b.x2 >> b.y2;
    int ans = longest_edge(a, b);
    ans *= ans;
    cout << ans;
    return 0;
}