
# Overview 

The RAII Idiom is aimed at creating a logical (i.e. code related) link between a CPP Object Lifecycle and Resource(s) ownership 

# Comments 

- Advantages 
  - Error-free Resource Acqusition and Release 
    - Object Constructors and Destructors are guaranteed to be called by the CPP Framework 
    - Linking the Resource Acquisition and Realease in that points provides a theoretical guarantee of correctness 
