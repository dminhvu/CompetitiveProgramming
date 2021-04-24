#include<bits/stdc++.h>

using namespace std;
const int N = 2e5 + 5;
const int mod = 1e9 + 7;

int64_t inv[N];

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    inv[1] = 1;
    for (int i = 2; i <= 1000; i++) {
        inv[i] = mod - (mod / i) * inv[mod % i] % mod;
    }
    // for (int i = 1; i <= 10; i++) cout << inv[i] << " ";
    cout << inv[1000];
    return 0;
}