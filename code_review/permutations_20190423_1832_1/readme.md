
# Overview 

The task is to compute all the permutations for a given vector of integers (but of course the specific integer type is not relevant for the solution)

The strategy is based on recursion + iterations 

At each recursion, the state consists of  

- the root sequence `a` which is the set of elements already placed 

- the remaining elements set `b` which is the set of elements still to be placed 

Inside the recursion, a loop places the `N(i)` (with `i` recursion index and) remaining elements producing the same amount of new root sequences and a new recursion is started so that `N(i+1)=N(i)-1` hence meaning the overall complexity is `O(N!)` as expected 

The recursion ends when there are no more elements to place hence `b.empty()` is true 

Each recursion set ends with a valid sequence hence they are all merged together in a final list of sequences 




