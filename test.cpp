#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < int(n); i++)
#define fore(i,a,b) for (int i = int(a); i <= int(b); i++)
#define ford(i,a,b) for (int i = int(a); i >= int(b); i--)
#define ll int64_t
#define sz(x) int(x.size())

using namespace std;
template<class t, class u> bool maxi(t &a, u b){ if (a < b){ a = b; return 1;} return 0;}
template<class t, class u> bool mini(t &a, u b){ if (a > b){ a = b; return 1;} return 0;}

int x[105];

int calc(int p, int n) {
   if (p == n) return 1;
   int ans = 0;
   if (p > 0) {
      if (x[p - 1] == 0) {
         x[p] = 1;
         ans += calc(p + 1, n);
      } else {
         x[p] = 0;
         ans += calc(p + 1, n);
         x[p] = 1;
         ans += calc(p + 1, n);
      }
   } else {
      x[p] = 0;
      ans += calc(p + 1, n);
      x[p] = 1;
      ans += calc(p + 1, n);
   }
   return ans;
}

int pow2(int n) {
   int ans = 1;
   for(int i = 2; i <= n; i++) ans *= 2;
   return ans;
}

int fact(int n) {
   int ans = 1;
   for (int i = 1; i <= n; i++) ans *= i;
}

int sigma(int n) {
   int ans = 0;
   for (int i = 2; i <= n; i++) ans += fact(i);
   return ans;
}

int calc2(int n) {
   return pow2(n) - sigma(n - 2);
}
int main() {
   ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
   memset(x, -1, sizeof x);
   int n = 6;
   cout << calc(0, n) << '\n';
   cout << calc2(n);
   return 0;
}