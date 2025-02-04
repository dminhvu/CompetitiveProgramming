#include<bits/stdc++.h>
long long n,i,j,h,k,t,d,m;
long double xa,xb,xc,ya,yb,yc,pi=3.14159265358979323846,esq,sq,e=1e-6,l,r;
using namespace std;
long double csquare(long double r)
{
    return r*r*pi;
}
long double sqr(long double x)
{
    return x*x;
}
long double dis(long double x1,long double y1, long double x2,long double y2)
{
   return sqrt(sqr(x1-x2)+sqr(y1-y2));
}
long double cosa()
{
    long double a1,a2,b1,b2;
    a1=xa-xc;
    a2=xb-xc;
    b1=ya-yc;
    b2=yb-yc;
    return (a1*a2+b1*b2)/(sqrt(sqr(a1)+sqr(b1))*sqrt(sqr(a2)+sqr(b2)));
}
long double alpha()
{
    long double res= acos(cosa());
    return min(res,2*pi-res);
}
long double triangleSquare()
{
    return 0.5*abs((xb-xa)*(yc-ya)-(xc-xa)*(yb-ya));
}
string xl()
{
    if (abs(dis(xa,ya,xc,yc)-r)>e) return "NO";
    if (abs(dis(xb,yb,xc,yc)-r)>e) return "NO";
    sq=csquare(r);
    l=sq*(esq-5)/100-e;
    r=sq*(esq+5)/100+e;
    sq=sq*alpha()/(2*pi);
    sq-=triangleSquare();
    if (sq<l||sq>r) return "NO";
    return "YES";
}
int main()
{
    cin>>xa>>ya>>xb>>yb>>xc>>yc>>r>>esq;
    cout<<xl();
}
