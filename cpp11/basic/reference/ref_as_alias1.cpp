// Reference as an Alias for an LValue 
// Se it running at 
// https://ideone.com/7BKVLZ

#include <iostream>
using namespace std;

// Declare and Init 
int a=11; 

// R1 is an alias for a 
int &r1 = a; 

int &r2 = r1; 


int main() {
	// your code goes here
	std::cout << "A = " << std::to_string(a) << ", "
		 "R1 = " << std::to_string(r1) << ", " 
		 "R2 = " << std::to_string(r2) << 
		 std::endl; 
	
	if(r1 == a) std::cout << "R1 Alias for A" << std::endl; 
	else std::cout << "R1 not an Alias for A" << std::endl;
	
	if(r2 == a) std::cout << "R2 Alias for A" << std::endl; 
	else std::cout << "R1 not an Alias for A" << std::endl; 
	return 0;
}
