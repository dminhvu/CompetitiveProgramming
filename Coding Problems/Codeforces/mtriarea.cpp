#include<bits/stdc++.h>

using namespace std;
const int N = 5e4 + 5;

struct Point
{
    int x, y;
    bool operator < (const Point &oth) const
    {
        return x<oth.x || (x==oth.x && y<oth.y);
    }
    bool operator == (const Point &oth) const 
    {
        return x==oth.x && y==oth.y;
    }
};

int n;
Point poly[2*N];
set<Point> a;

int ccw(Point O, Point A, Point B)
{
    return (A.x - O.x)*(B.y - O.y) - (B.x - O.x)*(A.y - O.y);
}

void findCV()
{
    int k = 1;
    for (set<Point>::iterator it=a.begin(); it!=a.end(); it++)
    {
        while (k>2 && ccw(poly[k - 2], poly[k - 1], *it)>0) --k;
        poly[k++] = *it;
    }
    int t = k - 2; --k;
    for (set<Point>::reverse_iterator it=a.rbegin(); it!=a.rend(); it++)
    {
        while (k>t+2 && ccw(poly[k - 2], poly[k - 1], *it)>0) --k;
        poly[k++] = *it;
    }
    n = k - 2;
}

double area(Point A, Point B, Point C)
{
    return fabs(A.x*(B.y - C.y) + B.x*(C.y - A.y) + C.x*(A.y - B.y))/2.0;
}

void Solve()
{
    a.clear();
    double res = 0.0;
    for (int i=1; i<=n; i++)
    {
        int x, y; cin >> x >> y;
        a.insert({x, y});
    }
    findCV();
    for (int i=1; i<=n; i++)
    {
        for (int j=i+1; j<=n; j++)
        {
            int l = j + 1, r = n;
            while (l<=r)
            {
                int mid = (l + r) >> 1;
                double area1 = area(poly[i], poly[j], poly[mid]);
                double area2 = area(poly[i], poly[j], poly[mid - 1]);
                res = max(res, area1);
                res = max(res, area2);
                if (area1>area2) l = mid + 1;
                else r = mid - 1;
            }
        }
    }
    cout << fixed << setprecision(2) << res << '\n';
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("input.txt","r",stdin);
    while (cin>>n && n!=-1) Solve();
}