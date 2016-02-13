
# Overview 

## Example1.cpp 

The `boost::asio::deadline_timer` is used to create an asynchronous repreating timer running every `n` sec for `m` timer 

### Notes 

#### N1 

The `boost::bind` makes copies of its arguments so to avoid it 

- pass by reference using `boost::ref()` for standard reference, and `boost::cref()` for constant reference 
- pass (shared) pointers 
  - in this case, passed objects are statically allocated hence they belong to the `main()` scope so there is no need to perform explicit deallocation (their allocation is static not dynamic) so no shared pointers but standard pointers 

