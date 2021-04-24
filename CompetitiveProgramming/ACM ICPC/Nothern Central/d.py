def isdivisible7(num): 
    n = len(num)
    if (n == 1):
        if (num=="0" or num=="7"): return 1
        else: return 0
    if (n % 3 == 1) : 
        num = str(num) + "00"
        n += 2
    elif (n % 3 == 2) : 
        num = str(num) + "0"
        n += 1
    GSum = 0
    p = 1
    for i in range(n - 1, -1, -1) : 
        group = 0
        group += ord(num[i]) - ord('0') 
        i -= 1
        group += (ord(num[i]) - ord('0')) * 10
        i -= 1
        group += (ord(num[i]) - ord('0')) * 100
        GSum = GSum + group * p 
        p *= (-1) 
    #print(GSum)
    return (GSum % 7 == 0) 

def findSum(str1, str2):  
    if (len(str1) > len(str2)): 
        t = str1; 
        str1 = str2; 
        str2 = t; 
    str = "";  
    n1 = len(str1); 
    n2 = len(str2);  
    str1 = str1[::-1];  
    str2 = str2[::-1];  
    carry = 0;  
    for i in range(n1):  
        sum = ((ord(str1[i]) - 48) + ((ord(str2[i]) - 48) + carry));  
        str += chr(sum % 10 + 48);  
        carry = int(sum / 10);  
    for i in range(n1, n2):  
        sum = ((ord(str2[i]) - 48) + carry)
        str += chr(sum % 10 + 48)
        carry = (int)(sum / 10)
    if (carry):  
        str += chr(carry + 48)
    str = str[::-1]
    return str;  

n = int(input())
for i in range(n):
    x = input()
    cnt = 0
    while (not isdivisible7(x)):
        rev = x[::-1]
        x = findSum(x, rev)
        cnt = cnt + 1
        #print(x)
        if cnt >= 1000: break
    if (cnt>=1000): print(-1)
    else: print(x)

