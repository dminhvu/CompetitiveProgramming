#include<bits/stdc++.h>

using namespace std;

void showbit(int x) {
    vector<int> v;
    while (x) {
        v.push_back(x%2);
        x /= 2;
    }
    while (v.size()) {
        cout << v.back();
        v.pop_back();
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("input.txt","r",stdin);
    int nTest; cin >> nTest;
    while (nTest--) {
        int64_t x, y; cin >> x >> y;
        if (x > y) {
            cout << "NO\n";
            continue;
        }
        while ((x << 1ll) <= y) x <<= 1ll;
        int64_t rem = y - x;
        vector<int> v1, v2;
        while (rem) {
            v2.push_back(rem%10ll);
            rem /= 10ll;
        }
        reverse(v2.begin(), v2.end());
        while (x) {
            v1.push_back(x/10ll);
            x /= 10ll;
        }
        reverse(v1.begin(), v1.end());
        bool f = 1;
        for (int i = 0; i < min(v1.size(), v2.size()); i++) f &= (v1[i] >= v2[i]);
        cout << (f ? "YES\n" : "NO\n");
    }
    return 0;
}