#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < int(n); i++)
#define fore(i,a,b) for (int i = int(a); i <= int(b); i++)
#define ford(i,a,b) for (int i = int(a); i >= int(b); i--)
#define ll int64_t
#define sz(x) int(x.size())

using namespace std;
template<class t, class u> bool maxi(t &a, u b){ if (a < b){ a = b; return 1;} return 0;}
template<class t, class u> bool mini(t &a, u b){ if (a > b){ a = b; return 1;} return 0;}

void bubble_sort(vector<int> &a) {
    int n = a.size();
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) swap(a[j], a[j + 1]);
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    vector<int> a = {6, 5, 2, 1, 3, 9};
    cout << "Initial array:\n";
    for(int x: a) cout << x << " ";
	cout << '\n';    
    
    // Time complexity: O(n^2)
    bubble_sort(a);
    
    cout << "After being sorted:\n";
	for(int x: a) cout << x << " ";
	cout << '\n';
    return 0;
}