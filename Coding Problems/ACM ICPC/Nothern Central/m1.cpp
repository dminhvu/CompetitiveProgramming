#include<bits/stdc++.h>

using namespace std;
const int N = 1e5 + 5;
const int64_t inf = 1e18;

struct ST
{
    int64_t sum, max, max_left, max_right;
};

ST st[N<<1];
int64_t a[N];
int n;

void build(int k, int l, int r)
{
    if (l>r) return;
    if (l==r)
    {
        st[k] = {a[l], a[l], a[l], a[l]};
        return;
    }
    int mid = (l + r) >> 1;
    build(k<<1,l,mid);
    build(l<<1|1,mid+1,r);

    st[k].sum = st[k<<1].sum + st[k<<1|1].sum;
    st[k].max_left = max(st[k<<1].max_left, st[k<<1].sum + st[k<<1|1].max_left);
    st[k].max_right = max(st[k<<1|1].max_right, st[k<<1].max_right + st[k<<1|1].sum);
    st[k].max = max(max(max(st[k].sum,st[k<<1].max_right + st[k<<1|1].max_left), st[k<<1].max), st[k<<1|1].max);
    st[k].max = max(st[k].max, st[k].max_left);
    st[k].max = max(st[k].max, st[k].max_right);
}

ST query(int k, int l, int r, int u, int v)
{
    if(l > r || l > v || r < u) return {-inf, -inf, -inf, -inf};

    if(l >= u && r <= v) return st[k];

    int mid = (l + r) >> 1;
    ST q1 = query(k<<1, l, mid, u, v);
    ST q2 = query(k<<1|1, mid + 1, r, u, v);

    ST q = {0, 0, 0, 0};
    q.sum = q1.sum + q2.sum;
    q.max_left = max(q1.max_left, q1.sum + q2.max_left);
    q.max_right = max(q2.max_right, q1.max_right + q2.sum);
    q.max = max(q1.max, q2.max);
    q.max = max(q.max, q1.max_right + q2.max_left);
    q.max = max(q.max, q1.sum + q2.sum);
    q.max = max(q.max, q.max_left);
    q.max = max(q.max, q.max_right);
    return q;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("input.txt","r",stdin);
    cin >> n;
    for (int i=1; i<=n; i++) cin >> a[i];
    build(1,1,n);
    cout << query(1,1,n,1,n).max << '\n';
}