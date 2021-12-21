#include<bits/stdc++.h>

using namespace std;
const int N = 2e5 + 10;

int n, m, p;
int64_t res = 0;
int64_t cnt[N];
int v[N];

pair<int, int> a[N];

int getid(int k)
{
    return lower_bound(v,v+p,k) - v + 1;
}

int64_t get(int pos)
{
    int64_t ans = 0;
    while (pos<N)
    {
        ans += cnt[pos];
        pos += pos & (-pos);
    }
    return ans;
}

void update(int pos)
{
    while (pos>0)
    {
        cnt[pos]++;
        pos -= pos & (-pos);
    }
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("input.txt","r",stdin);
    cin >> n >> m >> n >> m;
    p = 0;
    for (int i=1; i<=n; i++)
    {
        cin >> a[i].first >> a[i].second;
        v[p++] = a[i].first;
        v[p++] = a[i].second;
    }
    sort(v,v+p); unique(v,v+p);
    for (int i=1; i<=n; i++)
    {
        a[i].first = getid(a[i].first);
        a[i].second = getid(a[i].second);
    }
    sort(a+1,a+n+1);
    for (int i=1; i<=n; i++)
    {
        res += get(a[i].second + 1);
        update(a[i].second);
    }

    memset(cnt,0,sizeof cnt);
    p = 0;

    for (int i=1; i<=m; i++)
    {
        cin >> a[i].first >> a[i].second;
        v[p++] = a[i].first;
        v[p++] = a[i].second;
    }
    sort(v,v+p); unique(v,v+p);
    for (int i=1; i<=m; i++)
    {
        a[i].first = getid(a[i].first);
        a[i].second = getid(a[i].second);
    }
    sort(a+1,a+m+1);
    for (int i=1; i<=m; i++)
    {
        res += get(a[i].second + 1);
        update(a[i].second);
    }
    res += (int64_t)(n + 1) * (int64_t)(m + 1);
    cout << res;
}