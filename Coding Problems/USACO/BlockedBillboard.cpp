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

struct Point {
    int x1, y1, x2, y2;
};

int area(Point a) {
    return (a.x2 - a.x1) * (a.y2 - a.y1);
}

int intersect(Point a, Point b) {
    int ans = 0;
    int leny = max(0, min(a.y2, b.y2) - max(a.y1, b.y1));
    int lenx = max(0, min(a.x2, b.x2) - max(a.x1, b.x1));
    ans = leny * lenx;
    return ans;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    #ifdef OJ
    freopen("billboard.in","r",stdin);
    freopen("billboard.out","w",stdout);
    #endif
    // freopen("input.txt","r",stdin);
    vector<Point> a(3);
    rep(i,3) {
        cin >> a[i].x1 >> a[i].y1 >> a[i].x2 >> a[i].y2;
    }
    int ans = area(a[0]) + area(a[1]);
    ans -= intersect(a[0], a[2]);
    ans -= intersect(a[1], a[2]);
    cout << ans;
    return 0;
}