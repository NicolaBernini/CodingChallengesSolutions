
# Overview 

A list of test cases regarding Boost Thread use for Worker Thread 

## wt1.cpp 

A class implementing a Two Threads Producer / Consumer with discard Test Case 

- Producer Thread produces a set of results and put them into a Queue 
- Consumer Thread consumes just the first result in the Queue and clears the rest 
- Internal Sync performed with Mutex and Condition Variable 





