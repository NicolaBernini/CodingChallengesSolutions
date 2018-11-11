
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



# Using Exception 

Example of solution to the [Hackerrank Exceptoin Usage](https://www.hackerrank.com/challenges/exceptional-server/problem) is 

```cpp
try
{
    int res = Server::compute(A, B); 
    cout << res << endl; 
}
catch(std::invalid_argument& e) {cout << "Exception: " << e.what() << endl;}
catch(std::bad_alloc& ba) { cout << "Not enough memory" << endl; }
catch(std::exception& e) { cout << "Exception: " << e.what() << endl; }
catch(...) { cout << "Other Exception" << endl; }

```





