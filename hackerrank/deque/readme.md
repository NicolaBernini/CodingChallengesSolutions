
# Overview 

Some Deque related challenges 

[Sliding Window Max Search Problem](https://github.com/NicolaBernini/CPPSnippets1/blob/master/hackerrank/deque/deque_stl1.cpp)
- Solution to the problem defined [here](https://www.hackerrank.com/challenges/deque-stl/problem)
- Observations 
  - It can not be solved O(N) as non sliding window tracking because the history mutates because of the sliding window effect 
    - It means at some point the partial max can get out of the sliding window hence it will not be valid anymore 



