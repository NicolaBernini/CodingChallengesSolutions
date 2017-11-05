// Const Reference to RValue is OK 
// It probably initializes an LValue with the RValue 
// See it runnning 
// https://ideone.com/LmOYdC

#include <iostream>
using namespace std;

const int& r1 = 12; 

const int& r3 = r1; 

int main() {
	// your code goes here
	std::cout << "R1 = " << std::to_string(r1) << ", " 
		 "R2 = " << std::to_string(r3) << std::endl; 
	return 0;
}


