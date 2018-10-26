
# Overview 

Challenges with `std::string` appunto 

## String Reversing 

Solutions to [String Reverse Challenge at Hackerrank](https://www.hackerrank.com/contests/ngcjcjccg/challenges/string-reverse) 

- [String Reverse1](https://github.com/NicolaBernini/CPPSnippets1/blob/master/hackerrank/string/string_reverse1.cpp) and two problems are solved 
1. The char by char string reversion 
  - It is simply solved with an `O(N)` loop from `rbegin()` to `rend()` 
2. The word by word string reversion 
  - It is solved with a 2 step approach 
    - First an `O(N)` char by char string reversion using the previous solution 
    - Then an `O(N)` word explode, using `getline()` specifing the ' ' delimiter and reversing each specific word 







