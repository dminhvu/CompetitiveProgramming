#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'quartiles' function below.
#
# The function is expected to return an INTEGER_ARRAY.
# The function accepts INTEGER_ARRAY arr as parameter.
#

def std(arr):
    n = len(arr)
    if n % 2 == 0:
        return (arr[n // 2 - 1] + arr[n // 2]) / 2
    else:
        return arr[n // 2]
    
def quartiles(arr):
    # Write your code here
    n = len(arr)
    arr.sort()
    q1, q2, q3 = 0, 0, 0
    lower_half = []
    upper_half = []
    if n % 2 == 0:
        q2 = (arr[n//2 - 1] + arr[n//2]) / 2
        lower_half = [arr[i] for i in range(n//2)]
        upper_half = [arr[i] for i in range(n//2,n)]
    else:
        q2 = arr[n//2]
        lower_half = [arr[i] for i in range(n//2)]
        upper_half = [arr[i] for i in range(n//2 + 1, n)]
    q1 = std(lower_half)
    q3 = std(upper_half)
    return [int(q1), int(q2), int(q3)]

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input().strip())

    data = list(map(int, input().rstrip().split()))

    res = quartiles(data)

    fptr.write('\n'.join(map(str, res)))
    fptr.write('\n')

    fptr.close()
