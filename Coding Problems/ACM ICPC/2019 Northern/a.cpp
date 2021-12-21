#include<bits/stdc++.h>

using namespace std;

struct myData{
    int id; int64_t t, val;
    bool operator < (const myData &oth) const{
        return val<oth.val;
    }
};

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("input.txt","r",stdin);
    int nTest; cin >> nTest;
    while(nTest--){
        int n; cin >> n;
        set<myData> a;
        for(int i=0; i<n; i++){
            int x; int64_t y; cin >> x >> y;
            a.insert({x, y, x + y});
        }
        int q; cin >> q;
        vector<pair<int64_t, int> > query(q);
        for(int i=0; i<q; i++){
            cin >> query[i].first;
            query[i].second = i;
        }
        vector<int> ans(q, 0);
        sort(query.begin(), query.end());
        set<int> s;
        int64_t sum = 0;
        bool f = 1;
        for(int i=0; i<q; i++){
            while(a.size()){
                auto it = a.begin();
                int id = it->id;
                int64_t t = it->t;
                auto pos = lower_bound(s.begin(), s.end(), id);
                if (pos==s.end()){
                    int id2 = 0;
                    if (s.size()) id2 = *s.rbegin();
                    if (sum + id - id2 + t <= query[i].first){
                        sum += id - id2 + t;
                        s.insert(id);
                        a.erase(it);
                    } 
                    else break;
                }
                else{
                    int id2 = *pos;
                    if (sum + id2 - id + t <= query[i].first){
                        sum += id2 - id + t;
                        s.insert(id);
                        a.erase(it);
                    }
                    else break;
                }
            }
            ans[query[i].second] = s.size();
        }
        for(int i=0; i<q; i++) cout << ans[i] << " ";
    }
    return 0;
}