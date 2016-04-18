
# Overview 

A list of test cases regarding Boost Thread use for Worker Thread 

## wt1.cpp 

### Description 

A class implementing a Two Threads Producer / Consumer with discard Test Case 

- Producer Thread produces a set of results and put them into a Queue 
- Consumer Thread consumes just the first result in the Queue and clears the rest 
- Internal Sync performed with Mutex and Condition Variable 



### Working Example 

The Coliru <a href="http://coliru.stacked-crooked.com/a/18b439a9964ae83b" target="_blank">Test</a> appunto 

The Wandbox <a href="http://melpon.org/wandbox/permlink/06qhdQoIXwvWPxbV" target="_blank">Test</a> appunto 



