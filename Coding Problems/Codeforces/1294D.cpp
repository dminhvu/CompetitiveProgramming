#include<bits/stdc++.h>
#define ntu

using namespace std;

int x, cur = 0;
multiset<int> ms;
map<int, int> cnt;

int main()
{
#ifdef ntu
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int q; cin >> q >> x;
    int acc = 0;
    while (q--)
    {
        int num; cin >> num;
        
        cout << cur << '\n';
    }
    return 0;
}

/*
    add num to a[]
    a[i] + x * k == cur
    a[i] - x * k == cur
    => ++cur
    using set
    if exists cur - x * k or cur + x * k
    => increase cur by one, erase value cur - x * k or cur + x * k in set, insert old cur
*/