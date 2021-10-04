#include<bits/stdc++.h>

using namespace std;
const int N = 1e6 + 5;

bitset<N> bs;
vector<int> prime;
int res[N];

void Sieve() {
    for (int i = 2; i * i < N; i++) {
        if (bs[i] == 0) {
            for (int j = i * i; j < N; j += i) bs[j] = 1;
        }
    }
    for (int i = 2; i < N ; i++) {
        if (prime.size() >= 1000000) break;
        if (bs[i] == 0) prime.push_back(i);
    }
    int cnt = 0;
    auto it = prime.begin();
    for (int i = 0; i < N ; i++) {
        if (*it <= i) {
            ++cnt;
            ++it;
        }
        res[i] = cnt;
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("input.txt","r",stdin);
    int nTest; cin >> nTest;
    Sieve();
    while (nTest--) {
        int x, y; cin >> x >> y;
        if (res[x] > y) cout << "Divyam\n";
        else cout << "Chef\n";
    }
    return 0;
}
