
# Overview 

Here is my minimal solution about the problem 

- the strategy is divide-and-conquer for the reasons already explained by @papagaga 

- it is based on the idea that before the rotation the array has this structure 

```
[m .. p P .. M]
```

with 

- `m` min 

- `M` max 

- `p` pivot
 
- `P` next to the pivot so that `P>p`


- while after the rotation it has the following structure 

```
[P .. M m .. p]
```

so the idea is to update the `l` left cursor and `r` right cursor so that `v[l] > v[r]` with a divide and conquer strategy so to have `O(LogN)` complexity and ultimately the final condition is `l` and `r` are contiguous 
and the first identifies `M` while the second identifies `m` hence return the last one 

**EDIT** Following @papagaga suggestion I provide 2 implementations 

- [Article on CodeReview StackExchange](https://codereview.stackexchange.com/questions/217897/find-the-smallest-element-in-a-sorted-and-rotated-array/217949#217949)


## 1. Index based solution 

[Index based](index_based1.cpp)

Comments  

- Added the empty array case management using Exception 
- An alternative could have been using Maybe Monad (a Boost Optional) to represent non meaningful results 


## 2. Iterators based solution 

[Iterators based](iterator_based1.cpp)

Comments 

- Working with iterators allows to represent invalid values so no need for Exception and explicit Maybe Monad as the iterator type is one 
- The first check automatically manages the one element case 
- The empty array case should be managed before calling this function as it expects both the iterators point to valid elements 







