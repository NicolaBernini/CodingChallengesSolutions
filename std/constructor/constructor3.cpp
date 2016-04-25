#include <iostream>

#define STR_DEF_ARG 
//#define STR_DEF_ARG = ""

class A
{
    public: 
    
    A() : m_str("")
    {
        std::cout << "Default Constructor with no arguments internally invoking std::string(const char*) constructor" << std::endl; 
    }
    
    A(const std::string& in_str STR_DEF_ARG) : m_str(in_str) 
    {
        std::cout << "Constructor const std::string& internally invoking std::string copy constructor " << std::endl; 
    }
    
    A(const char* in_str STR_DEF_ARG) : m_str(in_str)
    {
        std::cout << "Constructor const char* internally invoking std::string(const char*) constructor" << std::endl; 
    }
    
    private: 
    std::string m_str; 
};

int main()
{
    //** Won't work if STR_DEF_ARG is not empty because of ambiguity otherwise the first constructor is called 
    A a; 
    
    A b("test1"); 
    
    A c(std::string("test3")); 
}


