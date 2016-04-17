#include <iostream>
using namespace std;

/**
  * @brief Type-generic Adder Class which relies on the right implementation of the "sum operator" (represented by plus symbol)
  */
template<typename T>
class Adder
{
	public: 
	Adder(const T& a, const T& b); 
	T getResult(); 
	
	private: 
	const T& m_a; 
	const T& m_b; 
};

/**
  * @brief The constructor saves internal references to the objects to be summed 
  */
template<typename T>
Adder<T>::Adder(const T& a, const T& b) : m_a(a), m_b(b) {}

/**
  * @brief It returns the result of the "sum operator" defined for the specific type 
  */
template<typename T>
T Adder<T>::getResult()
{
	return m_a+m_b; 
}

/**
  * @brief Sums int, floats and strings and observe the appropriate behaviour 
  * @note Numeric sum is mathematically well defined 
  * @note String sum is concatenation 
  */
int main() {
	// your code goes here
	int a1 = 10; 
	int b1 = 12; 
	double a2 = 22.5; 
	double b2 = 56.55; 
	
	std::cout << "Summing " << a1 << " and " << b1 << " = " << Adder<int>(a1,b1).getResult() << std::endl;
	std::cout << "Summing " << a2 << " and " << b2 << " = " << Adder<float>(a2,b2).getResult() << std::endl;
	std::cout << "Summing " << a2 << " and " << b2 << " = " << Adder<std::string>("aaa","bbb").getResult() << std::endl;
	return 0;
}
