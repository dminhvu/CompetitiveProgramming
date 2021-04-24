#include <bits/stdc++.h>
#define ll long long
#define Pii pair<int, int>
#define _mp make_pair
#define st first
#define nd second
const ll MAXX = 9223372036854775807LL; 
using namespace std;

ll T, n, cnt = 0;

int stringToNum(char c)    
{
    return c - '0';
}
 
char numToString(int n)    
{
    return (char)(n+48);
}

string _num2String(ll x){
    if(x == 0) return "0";
    bool Nega = 0;
    if(x < 0) Nega = 1;
    x = abs(x);

    string Res = "";
    while(x){
        int t = x % 10;
        Res = numToString(t) + Res;
        x /= 10;
    }
    if(Nega) Res = '-' + Res;
    return Res;
}

void chuanHoa(string &a, string &b) 
{
    int l1 = a.length(), l2 = b.length();
    if (l1 >= l2)
    {
        b.insert(0, l1-l2, '0');    
    }
    else
    {
        a.insert(0, l2-l1, '0');    
    }
}
 
string _sum(string a, string b) 
{
    string s = "";
    chuanHoa(a,b); 
    int l = a.length();
     
    int temp = 0;
    for (int i=l-1; i>=0; i--)   
    {
        temp = stringToNum(a[i]) + stringToNum(b[i]) + temp; 
        s.insert(0,1,numToString(temp%10));  
        temp = temp/10; 
    }
    if (temp>0)
    {
        s.insert(0,1,numToString(temp));
    } 
    return s;
}

string _step(string x){
    string Res = "";
    string tmp = x.substr(0, x.size()-1);
    int v = stringToNum(x[x.size()-1]);
    v *= 2;
    if(tmp.size() == 1){
        int tmpRes = (int)stringToNum(tmp[0]) - v;
        return _num2String(tmpRes);
    }
    string tmpV = _num2String(v);
    while(tmpV.size() < tmp.size()) tmpV = '0' + tmpV;  

    int Mem = 0;
    for(int i = tmp.size()-1; i >= 0; i--){
        int tmpR = stringToNum(tmp[i]) - stringToNum(tmpV[i]) - Mem;
        Mem = 0;
        if(tmpR < 0)
            tmpR += 10, Mem = 1;
        Res = numToString(tmpR) + Res;
    }
    return Res;
}

bool _stringD7(string x){
    while(x.size() > 1){
        x = _step(x);
        if(x[0] == '-' && x.size() == 2)
            return (x[1] == '0' || x[1] == '7');
        if(x == "-1") 
            return false;
        if(x.size() == 1)
            return (x == "0" || x == "7");
    }
    return false;
}

ll _reverse(ll t){
    ll tmp = 0;
    while(t){
        tmp *= 10;
        tmp += t % 10;
        t /= 10;
    }
    return tmp;
}

int _numSize(ll x){
    int cnt = 0;
    while(x){
        x /= 10;
        cnt++;
    }
    return cnt;
}

ll _process(ll t){
    if(t < 10) 
        return t + t;
    else
        return t + _reverse(t);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("input.txt","r",stdin);
    cin >> T;
    while(T--){
        string m = "";
        int Type = 1;
        bool Found = 0;
        cin >> n;
        while(cnt <= 1000){
            cnt++;
            if(Type == 1 && _numSize(n) <= 17){
                if(n % 7 == 0){
                    Found = 1;
                    break;
                }
                n = _process(n);
            }
            else{
                if(Type == 1){
                    m = _num2String(n);
                    Type = 2;
                }
                if(_stringD7(m)){
                    Found = 1;
                    break;
                }
                string m2 = m;
                reverse(m2.begin(), m2.end());
                m = _sum(m, m2);
            }  

        }
        if(Found == 1)
            if(Type == 1)
                cout << n << '\n';
            else  
                cout << m << '\n';
        else  
            cout << "-1\n";
        cnt = 0;
    }
    return 0;
}