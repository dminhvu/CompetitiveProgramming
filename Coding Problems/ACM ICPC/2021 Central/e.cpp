#include<bits/stdc++.h>
#define ll int64_t

using namespace std;
const ll inf = 1e18;
const int N = 100;

struct point
{
    ll x, y;
    bool operator < (const point &p) const 
    {
        return x<p.x || (x==p.x && y<p.y);
    }
};

set<point> s;
point upper[N], under[N];
int n;

ll cross(point o, point a, point b)
{
    return (a.x - o.x)*(b.y - o.y) - (a.y - o.y)*(b.x - o.x);
}

bool eraseHull()
{
    if (s.size()<3) return false;
    int k = 1, l = 1;
    for (set<point>::iterator it = s.begin(); it!=s.end(); it++)
    {
        while (k>=3 && cross(upper[k - 2], upper[k - 1], *it)>0) --k;
        upper[k++] = *it;
    }
    s.insert({-inf, -inf});
    for (set<point>::iterator it = prev(s.end()); it!=s.begin(); it--)
    {
        while (l>=3 && cross(under[l - 2], under[l - 1], *it)>0) --l;
        under[l++] = *it;
    }
    s.erase({-inf, -inf});
    for (int i=1; i<k; i++) s.erase(upper[i]);
    for (int i=1; i<l; i++) s.erase(under[i]);
    return true;
}

int main()
{
    // freopen("input.txt","r",stdin);
    int nTest; scanf("%d",&nTest);
    while (nTest--) {
        for (int i=1; i<=4; i++)
        {
            ll x, y; scanf("%lld%lld",&x,&y);
            s.insert({x, y});
        }
        eraseHull();
        if (s.empty()) printf("YES\n");
        else printf("NO\n");
        s.clear();
    }
    
    return 0;
}
