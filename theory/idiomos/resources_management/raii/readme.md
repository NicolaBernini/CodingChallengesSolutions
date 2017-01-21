
# Overview 

The RAII Idiom is aimed at creating a logical (i.e. code related) link between a CPP Object Lifecycle and Resource(s) ownership 

# Comments 

- Advantages 
  - Error-free Resource Acqusition and Release 
    - Object Constructors and Destructors are guaranteed to be called by the CPP Framework 
    - Linking the Resource Acquisition and Realease to Object Constructor and Destructor provides a theoretical guarantee of correctness 
- Disadvantages 
  - Requires Exception Handling 




# Examples 

RAII Resource Acquisition 

Algo 
- In Constructor 
  - Call the API to acquire the object 
    - Manage API errors: in case of error throw an exception 
      - **Note** If exception is thrown, CPP Framework guarantees the object is not constructed hence it can't be used and the destructor is not called 
- In Destructor 
  - Release the Resource 
    - **Note** CPP Framework guarantees destructor is not called if the object construction has not been previously successfully completed 

```cpp
class test
{
  public: 
  test() : m_resource(do_resource_acquire())  ///< Warning: the Acquisition API can fail 
  {
    if(!m_resource) {throw do_exception_create(MISSING_RESOURCE);}
  }
  
  ~test()  ///< Note: Destructor is invoked only if the object has previously been succesfully constructed hence the resource is owned and needs to be released 
  {
    do_resource_release(); 
  }
  
  private: 
  ResourceType m_resource; 
}
```



