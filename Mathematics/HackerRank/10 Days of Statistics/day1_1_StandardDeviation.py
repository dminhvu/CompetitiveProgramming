#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'stdDev' function below.
#
# The function accepts INTEGER_ARRAY arr as parameter.
#

def stdDev(arr):
    # Print your answers to 1 decimal place within this function
    n = len(arr)
    sum_of_arr = sum(arr)
    mean = sum_of_arr / n
    std = math.sqrt(sum([math.pow(arr[i] - mean, 2) for i in range(n)]) / n)
    print('{0:.1f}'.format(std))

if __name__ == '__main__':
    n = int(input().strip())

    vals = list(map(int, input().rstrip().split()))

    stdDev(vals)
