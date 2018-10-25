
# Overview 

Some Deque related challenges 

[Sliding Window Max Search Problem](https://github.com/NicolaBernini/CPPSnippets1/blob/master/hackerrank/deque/deque_stl1.cpp)
- Solution to the problem defined [here](https://www.hackerrank.com/challenges/deque-stl/problem)


# Observations 

The max search on an array can be solved O(N) (minimum required to observe all the items) just tracking the max hence comparing each new observation with the partial best 

This kind of solution does not work in this case because while the sliding window moves the tracked max will eventually get out of it hence it won’t be valid anymore 

Naive solution is `O(N*K)` as 
- `O(N)` needed to observe all the elements and
- `O(K)`  max search every time a new element is observed (with O(1) push and O(1) pop)

Two possible strategies 
1. Keep a sorted equivalent of the subarray observed by the sliding window
- max search is `O(1)` but performing sorted insert and search + remove is O(N)

2. Identify the invalid max case and recompute max only when needed
- Worst case: `O(N*K)` when max invalidation happens at every new observation 
- Best Case: `O(N)` when the max invalidation never happens





