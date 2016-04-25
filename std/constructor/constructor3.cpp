/**
  * @brief Another example regarding Constructor Ambiguity in case of Default Arguments 
  * @note To see it running visit http://ideone.com/GjFzxS 
  */
#include <iostream>

#define STR_DEF_ARG 
//#define STR_DEF_ARG = ""

class A
{
    public: 
    /**
      * @brief The Constructor with no Arguments 
      */
    A() : m_str("")
    {
        std::cout << "Default Constructor with no arguments internally invoking std::string(const char*) constructor" << std::endl; 
    }
    
    /**
      * @brief The Constructor taking a String and internally performing a copy 
      */
    A(const std::string& in_str STR_DEF_ARG) : m_str(in_str) 
    {
        std::cout << "Constructor const std::string& internally invoking std::string copy constructor " << std::endl; 
    }
    
    /**
      * @brief The Constructor taking a C String (hence an array of char) and internally building a String with it 
      */
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


