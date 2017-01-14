
# Overview 

The Solution to the Hackerrank Push, Pop and Get Max Element Challenge [Link](https://www.hackerrank.com/challenges/maximum-element)

# Algo 

The goal is to perform an efficient Max computation: it can't simply be computed each time as this will lead to exceed the computational time limit. 

In order to do this, extra information are needed in addition to the vector of elements. 

## Extra Information: last max 

Let's assume to keep track of 
- the `last_max` value 
- a `last_max_updated_flag` signaling if the information is valid 

### Max Computation at Insert Time 

When a new element is added (insert time) assuming the max at time t-1 is known, it possible to compute max at time t by means of a O(1)  operation namely simple comparison: just check if the new element is bigger than the previous one. 

### Max Computational at Remove Time 

When an element is removed (remove time) under the assumption of keeping just the above mentioned information, no O(1) operation is possible to compute the new max. 

It is just possible to turn off the `last_max_updated_flag` to signal the `last_max` is obsolete. 

The actual `last_max` recomputation will be performed in a lazy evaluation way, when this information will be needed. 



