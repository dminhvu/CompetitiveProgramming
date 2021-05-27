#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < int(n); i++)
#define fore(i,a,b) for (int i = int(a); i <= int(b); i++)
#define ford(i,a,b) for (int i = int(a); i >= int(b); i--)
#define ll int64_t
#define sz(x) int(x.size())

using namespace std;
template<class t, class u> bool maxi(t &a, u b){ if (a < b){ a = b; return 1;} return 0;}
template<class t, class u> bool mini(t &a, u b){ if (a > b){ a = b; return 1;} return 0;}

void merge_array(vector<int> &a, int l, int mid, int r) {
	int n1 = mid - l + 1;
	int n2 = r - mid;
	vector<int> v1, v2;
	for(int i = 0; i < n1; i++) v1.push_back(a[i + l]);
	for(int i = 0; i < n2; i++) v2.push_back(a[i + mid + 1]);
	int k = l;
	for(int i = 0, j = 0; i < n1 || j < n2; ) {
		if (i < n1 && j < n2) {
			if (v1[i] < v2[j]) {
				a[k++] = v1[i++];
			} else {
				a[k++] = v2[j++];
			}
		} else if (i < n1) {
			a[k++] = v1[i++];
		} else if (j < n2) {
			a[k++] = v2[j++];
		}
	}
}

void merge_sort(vector<int> &a, int l, int r) {
	if (l < r) {
		int mid = (l + r) >> 1;
		merge_sort(a, l, mid);
		merge_sort(a, mid + 1, r);
		merge_array(a, l, mid, r);
	}
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    vector<int> a = {6, 5, 2, 1, 3, 9};
    cout << "Initial array:\n";
    for(int x: a) cout << x << " ";
	cout << '\n';


	// Time complexity: O(nlogn)
    merge_sort(a, 0, a.size() - 1);
	
    cout << "After being sorted:\n";
	for(int x: a) cout << x << " ";
	cout << '\n';
    return 0;
}