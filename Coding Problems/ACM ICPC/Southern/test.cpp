#include<bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("input.txt","r",stdin);
    double a,b,c,delta;
    cin >> a >> b >> c;
    if (a == 0 && b == 0 && c==0) cout << "Countless solutions";
    else if (a == 0 and b == 0 and c != 0) cout << "No solution";
    else if (a==0 and b!=0 and c!=0) cout << fixed <<setprecision(4)<<-c/b;
    else 
    {
        delta = (b*b - 4.0*a*c);
        cout<<fixed<<setprecision(4);
        if (delta > 0 ) cout<<(-b+sqrt(delta))/(2.0*a)<<"\n"<<(-b-sqrt(delta))/(2.0*a);
        if (delta == 0) cout<<-b/(2.0*a);
        if (delta < 0) cout<<(-b/(2.0*a))<<" + "<<sqrt(-delta)/(2.0*a)<<"*i"<<"\n"<<(-b/(2.0*a))<<" - "<<sqrt(-delta)/(2.0*a)<<"*i";
    }
    return 0;
}