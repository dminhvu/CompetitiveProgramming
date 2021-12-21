#include<bits/stdc++.h>
#define int long long

using namespace std;
const int N = 1e5 + 5;

int A, B, n; 
pair<int, int> a[N];

bool cmp(pair<int, int> a, pair<int, int> b){
    return ((a.second - 1) / A + 1) * a.first < ((b.second - 1) / A + 1) * b.first;
}

int32_t main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("input.txt","r",stdin);
    int nTest; cin >> nTest;
    while (nTest--){
        cin >> A >> B >> n;
        for(int i=0; i<n; i++) cin >> a[i].first;
        for(int i=0; i<n; i++) cin >> a[i].second;
        int sum = 0;
        vector<int> c(n);
        for(int i=0; i<n; i++) c[i] = (a[i].second - 1) / A + 1;
        for(int i=0; i<n; i++) B -= c[i] * a[i].first;
        bool f = 0;
        for(int i=0; i<n; i++){
            B += c[i] * a[i].first;
            B -= (c[i] - 1) * a[i].first;
            if (B>0){
                f = 1;
                break;
            }
            B += (c[i] - 1) * a[i].first;
            B -= c[i] * a[i].first;
        }
        if (f) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}