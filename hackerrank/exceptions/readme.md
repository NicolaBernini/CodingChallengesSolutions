
# Overview 

Exercises on Exceptions 

# Defining Exceptions 

Example as solution to the [Hackerrank Exception Definition Problem](https://www.hackerrank.com/challenges/inherited-code/problem) is 

```cpp
class BadLengthException : public runtime_error
{
public: 
    BadLengthException(int n) : runtime_error(to_string(n)) {}
}; 
```



