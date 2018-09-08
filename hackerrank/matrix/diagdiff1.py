#!/bin/python

## Solution to https://www.hackerrank.com/challenges/diagonal-difference/problem

import math
import os
import random
import re
import sys

# The O(N) solution 
# Beside the obvious syntactic differences the main interesting one is the array length is not represented as a container property but it is returned by the keyword len() which represents the general way to get the monodimensisonal container number of element 
def diagonalDifference(arr):
    d1=0
    d2=0
    
    for i in range(len(arr)):
        d1 += arr[i][i]
        d2 += arr[i][len(arr)-1-i]
    return abs(d1-d2)
    
if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(raw_input())

    arr = []

    for _ in xrange(n):
        arr.append(map(int, raw_input().rstrip().split()))

    result = diagonalDifference(arr)

    fptr.write(str(result) + '\n')

    fptr.close()


