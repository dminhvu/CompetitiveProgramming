#include<bits/stdc++.h>

using namespace std;

vector<int> add(vector<int> a, vector<int> b){
    vector<int> ans;
    while (a.size()<b.size()) a.push_back(0);
    while (b.size()<a.size()) b.push_back(0);
    int r = 0;
    for(int i=0; i<a.size(); i++){
        int cur = a[i] + b[i] + r;
        ans.push_back(cur%10);
        r = cur/10;
    }
    if (r) ans.push_back(r);
    return ans;
}

vector<int> mul(vector<int> a, vector<int> b){
    vector<int> ans;
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    for(int i=0; i<a.size(); i++){
        vector<int> tmp;
        for(int j=0; j<i; j++) tmp.push_back(0);
        int r = 0;
        for(int j=0; j<b.size(); j++){
            int cur = a[i] * b[j] + r;
            tmp.push_back(cur%10);
            r = cur/10;
        }
        if (r) tmp.push_back(r);
        ans = add(ans, tmp);
    }
    while (ans.back()==0 && ans.size()>1) ans.pop_back();
    reverse(ans.begin(), ans.end());
    return ans;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("input.txt","r",stdin);
    int nTest; cin >> nTest;
    while (nTest--){
        vector<int> a, b;
        string s, t; cin >> s >> t;
        for(int i=0; i<s.size(); i++){
            a.push_back(s[i] - '0');
        }
        for(int i=0; i<t.size(); i++){
            b.push_back(t[i] - '0');
        }
        vector<int> ans;
        ans = mul(a, b);
        for(int x: ans) cout << x;
        cout << '\n';
    }
    return 0;
}