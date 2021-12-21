#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'weightedMean' function below.
#
# The function accepts following parameters:
#  1. INTEGER_ARRAY X
#  2. INTEGER_ARRAY W
#

def weightedMean(X, W):
    # Write your code here
    a = [X[i] * W[i] for i in range(len(X))]
    sum_of_a = 0
    for val in a:
        sum_of_a += val
    total_weight = 0
    for val in W:
        total_weight += val
    print('{0:.1f}'.format(sum_of_a / total_weight))

if __name__ == '__main__':
    n = int(input().strip())

    vals = list(map(int, input().rstrip().split()))

    weights = list(map(int, input().rstrip().split()))

    weightedMean(vals, weights)
