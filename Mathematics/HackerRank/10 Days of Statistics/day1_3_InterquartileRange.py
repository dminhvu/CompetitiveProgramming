#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'interQuartile' function below.
#
# The function accepts following parameters:
#  1. INTEGER_ARRAY values
#  2. INTEGER_ARRAY freqs
#

def std(arr):
    n = len(arr)
    if n % 2 == 0:
        return (arr[n // 2 - 1] + arr[n // 2]) / 2
    else:
        return arr[n // 2]
    
def interQuartile(values, freqs):
    # Print your answer to 1 decimal place within this function
    a = sorted([values[i] for i in range(len(values)) for _ in range(freqs[i])])
    n = len(a)
    q1, q3 = 0, 0
    if n % 2 == 0:
        q1 = std([a[i] for i in range(n//2)])
        q3 = std([a[i] for i in range(n//2, n)])
    else:
        q1 = std([a[i] for i in range(n//2)])
        q3 = std([a[i] for i in range(n//2 + 1, n)])
    print('{0:.1f}'.format(q3 - q1))
    
if __name__ == '__main__':
    n = int(input().strip())

    val = list(map(int, input().rstrip().split()))

    freq = list(map(int, input().rstrip().split()))

    interQuartile(val, freq)
