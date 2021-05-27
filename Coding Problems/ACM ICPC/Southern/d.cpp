#include<bits/stdc++.h>

using namespace std;

int64_t stringToNum(char c)
{
    return c - '0';
}

char numToString(int64_t n)
{
    return (char)(n + 48);
}

void init(string &a, string &b)
{
    int64_t l1 = a.size(), l2 = b.size();
    if (l1 >= l2)
    {
        b.insert(0, l1-l2, '0');
    }
    else
    {
        a.insert(0, l2-l1, '0');
    }
}

string add(string a, string b)
{
    string s = "";
    init(a, b);
    int64_t l = a.size();

    int64_t temp = 0;
    for (int64_t i=l-1; i>=0; i--)
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

string mul1(char a, string b)    
{
    string s = "";
    int64_t temp = 0;
    for (int64_t i=b.size()-1; i>=0; i--)      
    {
        temp = stringToNum(a) * stringToNum(b[i]) + temp;
        s.insert(0,1,numToString(temp%10));
        temp = temp/10;
    }

    if (temp>0)
    {
        s.insert(0,1,numToString(temp));
    } 
    return s;
}

string mul(string a, string b)
{
    string s = "";
    int64_t l = a.size();
    string s1[l];

    for (int64_t i=l-1; i>=0; i--)
    {
        s1[i] = mul1(a[i], b);
        s1[i].insert(s1[i].length(), l - i - 1, '0');   
        s = add(s, s1[i]);
    }
    return s;
}

string toString(int64_t a)
{
    string res = "";
    while (a)
    {
        int64_t r = a%10;
        res += ((char)(r + '0'));
        a/=10;
    }
    reverse(res.begin(), res.end());
    while (res.size()>1 && res[0]=='0') res.erase(0, 1);
    return res;
}

int64_t getNum(string s)
{
    while (s.size()>1)
    {
        int64_t sum = 0;
        for (int i=0; i<s.size(); i++)
        {
            sum += s[i] - '0';
        }
        s = toString(sum);
    }
    return (int64_t)(s[0] - '0');
}

int64_t getAns(int64_t x)
{
    while (x>=10)
    {
        int64_t sum = 0;
        while (x)
        {
            sum += x%10;
            x/=10;
        }
        x = sum;
    }
    return x;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    //freopen("input.txt","r",stdin);
    /*for (int i=1; i<=100000; i++) cout << 2;
    cout << '\n';
    for (int i=1; i<=100000; i++) cout << 9;*/
    string a, b;
    cin >> a >> b;
    if (a==b)
    {
        int64_t s = 0;
        for (int i=0; i<a.size(); i++) s += (a[i] - '0');
        cout << s%10;
    }
    else 
    {
        int64_t cnt = 1;
        int64_t p = getNum(a);
        while (a!=b)
        {
            ++cnt;
            if (cnt>=6) return cout << "9\n", 0;
            string aa = add(a, "1");
            p *= getNum(aa);
            p = getAns(p);
            //cout << p << '\n';
            a = add(a, "1");
        }
        p = getAns(p);
        cout << p;
    }
    return 0; 
}