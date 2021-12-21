#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < int(n); i++)
#define fore(i,a,b) for (int i = int(a); i <= int(b); i++)
#define ford(i,a,b) for (int i = int(a); i >= int(b); i--)
#define ll int64_t
#define pb push_back
#define fi first
#define se second
#define sz(x) int(x.size())

using namespace std;
template<class t, class u> bool maxi(t &a, u b){ if (a < b){ a = b; return 1;} return 0;}
template<class t, class u> bool mini(t &a, u b){ if (a > b){ a = b; return 1;} return 0;}
const int N = 5e2 + 5;
const ll inf = 1e18;

bool row[N], col[N], curRow[N], curCol[N];
ll a[N][N], b[N][N];
ll ans;
int n;
vector<pair<int, int> > pos;

void calc(int u, ll cur = 0) {
    if (u >= sz(pos)) {
        bool f = 1;
        return;
    }
    calc(u + 1, cur);
    a[pos[u].fi][pos[u].se] = 0;
    calc(u + 1, cur + b[u][v]);
    a[pos[u].fi][pos[u].se] = 1;
    calc(u + 1, cur + b[u][v]);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("input.txt","r",stdin);
    int t; cin >> t;
    fore(nT,1,t) {
        cin >> n;
        ans = inf;
        pos.clear();
        fore(i,1,n) {
            fore(j,1,n) {
                cin >> a[i][j];
                if (a[i][j] == -1) pos.pb({i, j});
            }
        }
        fore(i,1,n) {
            fore(j,1,n) {
                cin >> b[i][j];
            }
        }
        fore(i,1,n) cin >> row[i];
        fore(i,1,n) cin >> col[i];
        calc(1);
        cout << "Case #" << nT << ": " << ans << '\n';
    }
    return 0;
}