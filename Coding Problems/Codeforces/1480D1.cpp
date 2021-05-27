#include<bits/stdc++.h>

using namespace std;
int n;
vector<int> a;

int calc2(){
    vector<int> b, c;
    for(int i=0; i<n; i++){
        auto k = find(c.begin(), c.end(), a[i]);
        if (k==c.end() || (c.empty() || (!c.empty() && c.back()!=a[i]))){
            c.push_back(a[i]);
            continue;
        }
        k = find(b.begin(), b.end(), a[i]);
        if (k==b.end() || (b.empty() || (!b.empty() && b.back()!=a[i]))){
            b.push_back(a[i]);
            continue;
        }
    }
    return (int)(b.size() + c.size());
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    a.resize(n);
    for(int i=0; i<n; i++) cin >> a[i];
    vector<pair<int, int> > b, c;
    for(int i=0; i<n; i++){
        if (b.empty() || (!b.empty() && b.back().second!=a[i])){
            b.push_back({i, a[i]});
            continue;
        }
        c.push_back({i, a[i]});
    }
    for(int i=0; i<c.size(); i++){
        int k = upper_bound(b.begin(), b.end(), {c[i].first, 0}) - b.begin();
        if (k==-1) continue;
        bool f1 = (k==0 || (k > 0 && b[k - 1].second != c[i].second));
        bool f2 = (b[k] != c[i]);
        if (f1 && f2){
            b.insert(k - 1, {i, c[i]});
            c.erase(i, 1);
        }
    }
    cout << max(calc1(), calc2());
    return 0;
}