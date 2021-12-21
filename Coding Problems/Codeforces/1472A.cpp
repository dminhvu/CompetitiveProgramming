#include<bits/stdc++.h>

using namespace std;

int _pow(int a, int b){
    if (b==0) return 1;
    if (b==1) return a;
    int tmp = _pow(a, b/2);
    if (b&1) return tmp*tmp*a;
    return tmp*tmp;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int nTest; cin >> nTest;
    while (nTest--){
        int a, b, c; cin >> a >> b >> c;
        int cnt = 0;
        while (a%2==0) cnt++, a/=2;
        while (b%2==0) cnt++, b/=2;
        if (_pow(2, cnt) >= c) cout << "YEs\n";
        else cout << "NO\n";
    }
    return 0;
}