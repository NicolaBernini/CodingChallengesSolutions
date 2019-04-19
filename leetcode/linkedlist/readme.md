
# Overview 

Some LinkedList Related Exercises 

# Add Two Number 

```
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example:

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.

```
- [Def](https://leetcode.com/problems/add-two-numbers/)
- [Sol CPP](add_two_numbers1.cpp)
  - Time Complexity: Linear (Optimal)
  - Memory Complexity: Linear (Optimal)






## Explanation 

There are 2 possible approaches 

1) Conversions based 

2) Porting Arithmetic into the original representation 



### 1. Conversion based 

Operations are representation / type specific: for example, C and C++ provide support for sum operation for numeric types (int, float, …) but it’s not possible to sum 2 numbers represented as strings (not to be confused with the fact the operator ‘+’ on string can be used to perform concatenation, the focus is on the arithmetic operator) 

In order to be able to sum them, a string to numeric conversion needs to be performed first and this is typically a good approach as the internal parsing is able to catch valid strings which have meaningless numeric representation before entering the actual operation 

Using this approach for this problem, would mean 
- spend O(N) converting the linked lists into a big enough numeric type (e.g. unsigned long int)
- sum the numeric types using the language support
- spend O(N) converting back from the numeric type to the linked list

Letting the complexity aside, this approach can have scalability issues related to the fact the internal numeric representation could be a bottleneck as it might not be able to represent very big numbers resulting both from conversion and the sum operation 


### 2. Porting Arithmetic 

This approach does not rely on any type conversion, instead it consists of implementing the sum arithmetic directly on the Linked List representation 

This solution is certainly much more scalable as it is not affected by the language specific numeric type limits 

The tricky thing here is each node in the linked list represents one digit only but sum can overflow as for example 9+2 = 11 (it’s 2 digit and not just 1)

The carry needs to be ported as an additional term into the next digit sum but let’s pay attention to the fact the linked list allows cheap iteration in one direction only (it’s not a double linked list) 

So does linked list allow to implement carry efficiently or will we need a conversion step to use an other data structure because of carry, ultimately getting to an hybrid solution between the 2 types ? 

Fortunately, this specific apparently reversed representation is carry-friendly: typically numbers have the most significant digit leftmost while this linked list has less significant digit at its root, it means when we sum elements `a[i]` and `b[i]` we get both `d[i]` the corresponding final digit and the `r[i+1]` which is the carry term to be added to the next element which is more significant and the next in the linked list 

We can hence compute the sum result directly operating in the linked list representation efficiently as we are on linear complexity which is optimal (we have to observe each digit at least once to compute)








