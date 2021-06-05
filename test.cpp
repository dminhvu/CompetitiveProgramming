#include<bits/stdc++.h>

using namespace std;

int main() {
    int n=7,m=8;
    int* p1= &n, *p2=&m;
    *p1 +=12-m+ (*p2);
    *p2 = m + n- 2*(*p1);
    cout << m << '\n';
    cout << n << '\n';
    cout << m + n;
}