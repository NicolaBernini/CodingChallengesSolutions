/**
  * @brief Solution to Test Problem 
  * @link http://www.spoj.com/problems/TEST/
  */

#include <iostream>
using namespace std;

int main() {
	// your code goes here
	std::string temp = ""; 
	do
	{
		if(temp!="") std::cout << temp << std::endl; 
		std::cin >> temp; 
	}while(temp != "42"); 
	return 0;
}






