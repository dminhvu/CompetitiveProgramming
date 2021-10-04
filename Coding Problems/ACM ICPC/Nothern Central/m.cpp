#include<bits/stdc++.h>

using namespace std;
const int N = 1e5 + 5;
const int64_t inf = 1e18;

int n;
int64_t a[N];
int64_t S[N], F[N], P[N];

void solve1()
{

}

void solve2()
{

}

int main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("input.txt","r",stdin);
    cin >> n;
    S[0] = F[0] = 0;
    for (int i=1; i<=n; i++) cin >> a[i];
    for (int i=1; i<=n; i++) S[i] = S[i - 1] + a[i];
    for (int i=1; i<=n; i++) F[i] = F[i - 1] + S[i];
    int64_t ans = -inf;
    for (int i=1; i<=n; i++)
    {
        for (int j=i; j<=n; j++)
        {
            cout << F[j] - F[i - 1] - 1ll * (j - i + 1) * S[i - 1] << " ";
        }
        cout << '\n';
        ans - max(ans, a[i]);
        if (n-i+1<=2)
        {
            if (i==n-1) ans = max(ans, F[n] - F[i - 1] - 1ll * (n - i + 1) * S[i - 1]);
            continue;
        }
        int64_t val[3];
        for (int j=i; j<=i+2; j++)
        {
            val[j - i] = F[j] - F[i - 1] - 1ll * (j - i + 1) * S[i - 1];
        }
        bool f = 0;
        if (val[0]<=val[1] && val[1]<=val[2]) f = 1;
        else if (val[0]>=val[1] && val[1]>=val[2]) f = 1;
        if (f)
        {
            int l = i, r = n;
            while (l<=r)
            {
                int mid = (l + r) >> 1;
                int64_t v1 = F[mid - 1] - F[i - 1] - 1ll * (mid - 1 - i + 1) * S[i - 1];
                int64_t v2 = F[mid] - F[i - 1] - 1ll * (mid - i + 1) * S[i - 1];
                if (v2>=v1)
                {
                    ans = max(ans, v2);
                    l = mid + 1;
                }
                else 
                {
                    ans = max(ans, v1);
                    r = mid - 1;
                }
            }
        }
        else 
        {
            ans = max(ans, F[n] - F[i - 1] - 1ll * (n - i + 1) * S[i - 1]);
            if (i<=n-1) ans = max(ans, F[n - 1] - F[i - 1] - 1ll * (n - 1 - i + 1) * S[i - 1]);
        }
    }
    cout << ans;
}