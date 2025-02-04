#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < int(n); i++)
#define fore(i,a,b) for (int i = int(a); i <= int(b); i++)
#define ford(i,a,b) for (int i = int(a); i >= int(b); i--)
#define ll int64_t
#define sz(x) int(x.size())

using namespace std;
template<class t, class u> bool maxi(t &a, u b){ if (a < b){ a = b; return 1;} return 0;}
template<class t, class u> bool mini(t &a, u b){ if (a > b){ a = b; return 1;} return 0;}

int C;

void rotate_lock(vector<int> &a, int c, int r) {
    a[c] -= r;
    if (a[c] < 0) a[c] += C;
}

void rotate(vector<int> &a, vector<int> state) {
    int c = state[4];
    int r = state[5];
    if (state[0] == 0 && state[1] == 0 && state[2] == 0 && state[3] == 0) {
        rotate_lock(a, c, r);
    } else if (state[0] == 1 && state[1] == 0 && state[2] == 0 && state[3] == 0) {
        rotate_lock(a, 0, r);
        rotate_lock(a, 1, r);
        rotate_lock(a, 3, r);
        rotate_lock(a, 4, r);
    } else if (state[0] == 0 && state[1] == 1 && state[2] == 0 && state[3] == 0) {
        rotate_lock(a, 1, r);
        rotate_lock(a, 2, r);
        rotate_lock(a, 4, r);
        rotate_lock(a, 5, r);
    } else if (state[0] == 0 && state[1] == 0 && state[2] == 1 && state[3] == 0) {
        rotate_lock(a, 3, r);
        rotate_lock(a, 4, r);
        rotate_lock(a, 6, r);
        rotate_lock(a, 7, r);
    } else if (state[0] == 0 && state[1] == 0 && state[2] == 0 && state[3] == 1) {
        rotate_lock(a, 4, r);
        rotate_lock(a, 5, r);
        rotate_lock(a, 7, r);
        rotate_lock(a, 8, r);
    } else if (state[0] == 1 && state[1] == 1 && state[2] == 0 && state[3] == 0) {
        rotate_lock(a, 0, r);
        rotate_lock(a, 1, r);
        rotate_lock(a, 2, r);
        rotate_lock(a, 3, r);
        rotate_lock(a, 4, r);
        rotate_lock(a, 5, r);
    } else if (state[0] == 0 && state[1] == 1 && state[2] == 0 && state[3] == 1) {
        rotate_lock(a, 1, r);
        rotate_lock(a, 2, r);
        rotate_lock(a, 4, r);
        rotate_lock(a, 5, r);
        rotate_lock(a, 7, r);
        rotate_lock(a, 8, r);
    } else if (state[0] == 1 && state[1] == 0 && state[2] == 1 && state[3] == 0) {
        rotate_lock(a, 0, r);
        rotate_lock(a, 1, r);
        rotate_lock(a, 3, r);
        rotate_lock(a, 4, r);
        rotate_lock(a, 6, r);
        rotate_lock(a, 7, r);
    } else if (state[0] == 0 && state[1] == 0 && state[2] == 1 && state[3] == 1) {
        rotate_lock(a, 3, r);
        rotate_lock(a, 4, r);
        rotate_lock(a, 5, r);
        rotate_lock(a, 6, r);
        rotate_lock(a, 7, r);
        rotate_lock(a, 8, r);
    } else if (state[0] == 1 && state[1] == 1 && state[2] == 1 && state[3] == 1) {
        rep(i,9) rotate_lock(a, i, r);
    }
}

void print(vector<int> &a) {
    rep(i,9) {
        cout << a[i] << " ";
        if (i % 3 == 2) cout << '\n';
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("input.txt","r",stdin);
    cin >> C;
    vector<int> a(9);
    rep(i,9) cin >> a[i];
    rep(i,9) a[i] = (C - a[i] + C) % C;
    print(a);
    vector<int> st = {0, 0, 0, 0, 0, a[0]};
    rotate(a, st);
    st = {0, 0, 0, 0, 2, a[2]};
    rotate(a, st);
    st = {0, 0, 0, 0, 6, a[6]};
    rotate(a, st);
    st = {0, 0, 0, 0, 8, a[8]};
    rotate(a, st);
    // print(a);
    int i = 0;
    for (i = 0; i <= C; i++) {
        // if ((a[4] + i + 4 * (C - i)) % C == 0) {
        //     break;
        // }
        if ((C * 4 - 3 * i - a[4]) % C == 0) {
            break;
        }
    }
    cout << i << '\n';
    st = {1, 1, 1, 1, 0, i};
    rotate(a, st);
    // print(a);

    st = {1, 0, 0, 0, 0, C - i};
    rotate(a, st);
    // print(a);

    st = {0, 1, 0, 0, 0, C - i};
    rotate(a, st);
    // print(a);

    st = {0, 0, 1, 0, 0, C - i};
    rotate(a, st);
    st = {0, 0, 0, 1, 0, C - i};
    rotate(a, st);
    if (a[1] != 0) {
        int tmp = a[1];
        st = {1, 1, 0, 0, 0, C - tmp};
        rotate(a, st);
        // print(a);
        st = {1, 0, 0, 0, 0, tmp};
        rotate(a, st);
        // print(a);
        st = {0, 1, 0, 0, 0, tmp};
        rotate(a, st);
    }
    if (a[3] != 0) {
        int tmp = a[3];
        st = {1, 0, 1, 0, 0, C - tmp};
        rotate(a, st);
        // print(a);
        st = {1, 0, 0, 0, 0, tmp};
        rotate(a, st);
        // print(a);
        st = {0, 0, 1, 0, 0, tmp};
        rotate(a, st);
    }
    if (a[5] != 0) {
        int tmp = a[5];
        st = {0, 1, 0, 1, 0, C - tmp};
        rotate(a, st);
        // print(a);
        st = {0, 1, 0, 0, 0, tmp};
        rotate(a, st);
        // print(a);
        st = {0, 0, 0, 1, 0, tmp};
        rotate(a, st);
    }
    if (a[7] != 0) {
        int tmp = a[7];
        st = {0, 0, 1, 1, 0, C - tmp};
        rotate(a, st);
        // print(a);
        st = {0, 0, 1, 0, 0, tmp};
        rotate(a, st);
        // print(a);
        st = {0, 0, 0, 1, 0, tmp};
        rotate(a, st);
    }
    // print(a);
    
    
    print(a);
    return 0;
}