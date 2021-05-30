#include<bits/stdc++.h>

using namespace std;

int getMax(int x, int y) {
	int a = 0;
	(x > y) ? a = x : a = y;
	return a;
}
int main() {
	int x = 5, y = 6;
	cout << getMax(x, y);
}