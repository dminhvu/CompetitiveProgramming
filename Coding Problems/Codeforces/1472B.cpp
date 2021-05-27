#include<bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int nTest; cin >> nTest;
    while (nTest--){
        vector<int> cnt(2, 0);
        int n; cin >> n;
        for(int i=0; i<n; i++){
            int x; cin >> x;
            --x;
            cnt[x]++;
        }
        if (cnt[1]&1)
        {
            if (cnt[0]>=2 && cnt[0]%2==0) cout << "YES\n";
            else cout << "NO\n";
        }
        else if ((cnt[1] + cnt[0])%2==0) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}