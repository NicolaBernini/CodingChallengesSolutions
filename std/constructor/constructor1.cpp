
#include <iostream>

class A
{
public:
    A() : m_n(22) 
    {
        std::cout << "Empty Constructor" << std::endl; 
    }
    void print()
    {
        std::cout << "m_n = " << m_n << std::endl; 
    }

private:
    int m_n;
};

int main()
{
    //** Works and calls the constructor taking no arguments 
    //** Prints "Empty Constructor"
    A a; 
    
    //** Won't work as it is ambiguous with a function call declaration, taking no argument and returning A 
    //** Acatually the Language Standard specifies that this ambiguity is resolved in favour of the function hypothesis 
    //A a(); 
    
    //** Prints "m_n = 22" 
    a.print(); 
}

