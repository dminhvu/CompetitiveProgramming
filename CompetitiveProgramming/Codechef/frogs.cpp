#include<bits/stdc++.h>

using namespace std;

const int inf = 1e9;

struct myData {
    int w, l, pos;
    bool operator < (const myData &oth) const {
        return w<oth.w;
    }
};

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int nTest; cin >> nTest;
    while (nTest--) {
        int n; cin >> n;
        vector<myData> a(n + 1);
        for (int i = 1; i <= n; i++) cin >> a[i].w;
        for (int i = 1; i <= n; i++) cin >> a[i].l;
        for (int i = 1; i <= n; i++) a[i].pos = i;

        sort(a.begin() + 1, a.end());
        int ans = inf;
        if (n==2) {
            for (int i = 0; i * a[1].l < 25; i++) {
                for (int j = 0; j * a[2].l < 25; j++) {
                    if (a[1].pos + a[1].l * i < a[2].pos + a[2].l * j) {
                        ans = min(ans, i + j);
                    }
                }
            }
        } else if (n==3) {
            for (int i = 0; i * a[1].l < 25; i++) {
                for (int j = 0; j * a[2].l < 25; j++) {
                    for (int k = 0; k * a[3].l < 25; k++) {
                        int d1 = a[1].pos + a[1].l * i;
                        int d2 = a[2].pos + a[2].l * j;
                        int d3 = a[3].pos + a[3].l * k;
                        if (d1 < d2 && d2 < d3) {
                            ans = min(ans, i + j + k);
                        }
                    }
                }
            }
        } else {
            for (int i = 0; i * a[1].l < 25; i++) {
                for (int j = 0; j * a[2].l < 25; j++) {
                    for (int k = 0; k * a[3].l < 25; k++) {
                        for (int l = 0; l * a[4].l < 25; l++) {
                            int d1 = a[1].pos + a[1].l * i;
                            int d2 = a[2].pos + a[2].l * j;
                            int d3 = a[3].pos + a[3].l * k;
                            int d4 = a[4].pos + a[4].l * l;
                            if (d1 < d2 && d2 < d3 && d3 < d4) {
                                ans = min(ans, i + j + k + l);
                                break;
                            }
                        }
                    }
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}