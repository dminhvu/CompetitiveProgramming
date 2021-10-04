#include<bits/stdc++.h>
#define ntu

using namespace std;
const int N = 1e3 + 5;

struct point 
{
    int x, y;
};

bool cmpX(point a, point b)
{
    return a.x<b.x || (a.x==b.x && a.y<b.y);
}

bool cmpY(point a, point b)
{
    return a.y<b.y || (a.y==b.y && a.x<b.x);
}

int n, mxX, mxY;
point a[N];

bool check1()
{
    sort(a+1,a+n+1,cmpX);
    for (int i=1; i<=n; i++)
    {
        if (a[i].y < a[i - 1].y) return false;
    }
    return true;
}

bool check2()
{
    sort(a+1,a+n+1,cmpY);
    for (int i=1; i<=n; i++)
    {
        if (a[i].x < a[i - 1].x) return false;
    }
    return true;
}

void print()
{
    cout << "YES\n";
    int curX = 0, curY = 0;
    for (int i=1; i<=n; i++)
    {
        while (curX < a[i].x || curY < a[i].y)
        {
            if (curX==a[i].x)
            {
                curY++;
                cout << "U";
            }
            else 
            {
                curX++;
                cout << "R";
            }
        }
    }
    cout << '\n';
}

void Solve()
{
    cin >> n;
    mxX = mxY = -1000;
    for (int i=1; i<=n; i++) 
    {
        cin >> a[i].x >> a[i].y;
        mxX = max(mxX, a[i].x);
        mxY = max(mxY, a[i].y);
    }
    if (check1() || check2()) print();
    else cout << "NO\n";
}

int main()
{
#ifdef ntu
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int nTest; cin >> nTest;
    while (nTest--) Solve();
    return 0;
}