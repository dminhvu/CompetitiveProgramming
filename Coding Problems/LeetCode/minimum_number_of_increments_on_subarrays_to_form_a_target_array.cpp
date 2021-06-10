#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < int(n); i++)
#define fore(i,a,b) for (int i = int(a); i <= int(b); i++)
#define ford(i,a,b) for (int i = int(a); i >= int(b); i--)
#define ll int64_t
#define sz(x) int(x.size())

using namespace std;
template<class t, class u> bool maxi(t &a, u b){ if (a < b){ a = b; return 1;} return 0;}
template<class t, class u> bool mini(t &a, u b){ if (a > b){ a = b; return 1;} return 0;}
class SegTree {
public:
    struct SegmentTree {
        int orig_min_val;
        int updated_max_val;
        int diff;
    } st[int(4e5 + 5)];
    void build(int k, int l, int r, vector<int> target) {
        if (l > r) return;
        if (l == r) {
            st[k].orig_min_val = target[l];
            st[k].updated_max_val = 0;
            st[k].diff = 0;
            return;
        }
        int mid = (l + r) >> 1;
        build(k*2+1,l,mid,target);
        build(k*2+2,mid+1,r,target);
        st[k].orig_min_val = min(st[k*2+1].orig_min_val, st[k*2+2].orig_min_val);
    }
    void down(int k) {
        st[k*2+1].diff += st[k].diff;
        st[k*2+1].updated_max_val += st[k].diff;

        st[k*2+2].diff += st[k].diff;
        st[k*2+2].updated_max_val += st[k].diff;

        st[k].diff = 0;
    }
    int get_orig_min_val(int k, int l, int r, int u, int v) {
        if (r < u || l > v) return int(1e9);
        if (l >= u && r <= v) return st[k].orig_min_val;
        int mid = (l + r) >> 1;
        return min(get_orig_min_val(k*2+1,l,mid,u,v), get_orig_min_val(k*2+2,mid+1,r,u,v));
    }
    void update(int k, int l, int r, int u, int v, int diff) {
        if (r < u || l > v) return;
        if (l >= u && r <= v) {
            st[k].updated_max_val += diff;
            st[k].diff += diff;
            return;
        }
        down(k);
        int mid = (l + r) >> 1;
        update(k*2+1,l,mid,u,v,diff);
        update(k*2+2,mid+1,r,u,v,diff);
        st[k].updated_max_val = max(st[k*2+1].updated_max_val, st[k*2+2].updated_max_val);
    }
    int get_updated_max_value(int k, int l, int r, int u, int v) {
        if (l > v || r < u) return 0;
        if (l >= u && r <= v) return st[k].updated_max_val;
        down(k);
        int mid = (l + r) >> 1;
        return max(get_updated_max_value(k*2+1,l,mid,u,v), get_updated_max_value(k*2+2,mid+1,r,u,v));
    }
    void show(int k, int l, int r) {
        if (l > r) return;
        if (l == r) {
            cout << st[k].updated_max_val << " ";
            return;
        }
        down(k);
        int mid = (l + r) >> 1;
        show(k*2+1,l,mid);
        show(k*2+2,mid+1,r);
    }
};

class Solution {
public:
    struct range {
        int l, r;
        bool operator < (const range &oth) const {
            return l < oth.l || (l == oth.l && r > oth.r);
        }
    };
    int minNumberOperations(vector<int>& target) {
        int n = target.size();
        set<range> pos;
        vector<int> left(n), right(n);
        for (int i = 0; i < n; i++) {
            left[i] = i;
            while (left[i] > 0 && target[left[i] - 1] >= target[i]) left[i] = left[left[i] - 1];
        }
        for (int i = n - 1; i >= 0; i--) {
            right[i] = i;
            while (right[i] < n - 1 && target[right[i] + 1] >= target[i]) right[i] = right[right[i] + 1];
        }
        for (int i = 0; i < n; i++) {
            pos.insert({left[i], right[i]});
        }
        SegTree s;
        s.build(0,0,n-1,target);
        int ans = 0;
        for (auto it = pos.begin(); it != pos.end(); it++) {
            int u = it->l;
            int v = it->r;
            int max_added = s.get_updated_max_value(0,0,n-1,u,v);
            int min_orig = s.get_orig_min_val(0,0,n-1,u,v);
            ans += min_orig - max_added;
            s.update(0,0,n-1,u,v,min_orig - max_added);
        }
        return ans;
    }
};

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    Solution s;
    vector<int> target = {3,1,1,2};
    cout << s.minNumberOperations(target) << '\n';
    return 0;
}


