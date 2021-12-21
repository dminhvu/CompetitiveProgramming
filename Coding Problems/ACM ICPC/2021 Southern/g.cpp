#include<bits/stdc++.h>
long long n,i,j,h,k,t,d,m,a[200005],x[200005],y[200005],b[200005],l,r,mid,test;
using namespace std;
string s;

bool check(long long m)
{
    int i,j;
    long long d,xx,yy;
    xx=x[m];
    yy=y[m];
    //cout<<xx<<' '<<yy<<endl;
    for(i=n;i>=1;i--)
    {
        d=a[i];
   //  cout<<d<<endl;
        while (d>3&&yy>0)
        {
            yy--;
            d-=3;
        }
      //    cout<<d<<endl;
        while (d>1&&xx>0)
        {
            d-=2;
            xx--;
        }
        while (xx==0&&d>=2&&yy>0)
        {
            yy--;
            d-=3;
        }
      //  cout<<xx<<' '<<yy<<' '<<d<<endl;
        if (d>=2) return true;
    }
    return false;

}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);
    cin>>test;
    for(h=1;h<=test;h++)
    {
        cin >> s;
    d=0;
    for(i=0;i<s.size();i++) if (s[i]=='.') d++; else
    {
        if (d>1) {n++;a[n]=d;}
        d=0;
    }
    if (d>1) {n++;a[n]=d;}
    sort(a+1,a+n+1);
    cin>>s;
    for(i=0;i<s.size();i++)
    {
        if (s[i]=='M') x[i+1]++; else y[i+1]++;
        x[i+1]+=x[i];
        y[i+1]+=y[i];
    }
    l=0;r=s.size();
    while (l<=r)
    {
        mid=(l+r)/2;
        if (check(mid)) l=mid+1; else r=mid-1;
    }
    for(i=0;i<=s.size();i++) if (i<=r) cout<<'Y'; else cout<<'N';
    cout<<endl;
    }
}
