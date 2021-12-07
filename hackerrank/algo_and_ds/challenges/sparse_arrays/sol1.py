#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'matchingStrings' function below.
#
# The function is expected to return an INTEGER_ARRAY.
# The function accepts following parameters:
#  1. STRING_ARRAY strings
#  2. STRING_ARRAY queries
#

def matchingStrings(strings, queries):
    # Write your code here
    res = [0] * len(queries)
    #dq = {}    
    #for i in range(len(queries)):
    #    dq[queries[i]] = i
    #for s in strings:
    #    if s in dq.keys():
    #        res[dq[s]] += 1

    ds = {}
    for s in strings:
        if s not in ds:
            ds[s] = 1
        else:
            ds[s] += 1
        
    for i in range(len(queries)):
        if queries[i] in ds.keys():
            res[i] = ds[queries[i]]

    return res


if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    strings_count = int(input().strip())

    strings = []

    for _ in range(strings_count):
        strings_item = input()
        strings.append(strings_item)

    queries_count = int(input().strip())

    queries = []

    for _ in range(queries_count):
        queries_item = input()
        queries.append(queries_item)

    res = matchingStrings(strings, queries)

    fptr.write('\n'.join(map(str, res)))
    fptr.write('\n')

    fptr.close()
