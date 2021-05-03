#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < int(n); i++)
#define fore(i,a,b) for (int i = int(a); i <= int(b); i++)
#define ford(i,a,b) for (int i = int(a); i >= int(b); i--)
#define ll int64_t
#define sz(x) int(x.size())

using namespace std;
template<class t, class u> bool maxi(t &a, u b){ if (a < b){ a = b; return 1;} return 0;}
template<class t, class u> bool mini(t &a, u b){ if (a > b){ a = b; return 1;} return 0;}

void quick_sort(vector<int> &a, int l, int r) {
    if (l >= r) return;
    int pivot = a[(l + r) >> 1];
    int left = l, right = r;
    while (left <= right) {
        while (left <= right && a[left] < pivot) left++;
        while (left <= right && a[right] > pivot) right--;
        if (left > right) break;
        swap(a[left++], a[right--]);
    }
    quick_sort(a, left, r);
    quick_sort(a, l, right);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    vector<int> a = {6, 5, 2, 1, 3, 9};
    cout << "Initial array:\n";
    for(int x: a) cout << x << " ";
	cout << '\n';

    // Time complexity: O(n) or O(nlogn) or O(n^2)
    quick_sort(a, 0, a.size() - 1);
    
    cout << "After being sorted:\n";
	for(int x: a) cout << x << " ";
	cout << '\n';
    return 0;
}