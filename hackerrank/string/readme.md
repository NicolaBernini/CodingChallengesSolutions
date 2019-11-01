
# Overview 

Challenges with `std::string` appunto 

## Special String Again 

Solutions to [Special String Again](https://www.hackerrank.com/challenges/special-palindrome-again/problem) 

- [Solution1](special_string_again_20191101_1032_1.cpp)
  - Complexity: O(N) time and O(1) Space 
  

## String Reversing 

Solutions to [String Reverse Challenge at Hackerrank](https://www.hackerrank.com/contests/ngcjcjccg/challenges/string-reverse) 

- [String Reverse1](string_reverse1.cpp) and two problems are solved 
1. The char by char string reversion 
  - It is simply solved with an `O(N)` loop from `rbegin()` to `rend()` 
2. The word by word string reversion 
  - It is solved with a 2 step approach 
    - First an `O(N)` char by char string reversion using the previous solution 
    - Then an `O(N)` word explode, using `getline()` specifing the ' ' delimiter and reversing each specific word 



## Substring Find 

- The [Substring finding in 2 Strings on Hackerrank](https://www.hackerrank.com/challenges/two-strings/problem) 
- The goal is to check if 2 substrings has a common string but not to return the actual substring 
- This makes the actual problem much easier than it seems as a necessary and sufficient condition is they share a char so the [proposed solution1](substring_find1.cpp) focuses on solving this equivalent challenge 
- It is implemented representing a string as an unordered_map of its chars (store O(1), loop O(N)) and then iterating over the other string looking up for each char in the other string (lookup O(1), loop O(N))





