#include <iostream>
using namespace std;

/**
  * @brief It just counts the number of 1s in a given binary representation 
  */
unsigned int count_ones(const unsigned int n, const unsigned int partial=0)
{
	if(n==0) return partial; 
	return ( (n&1)==0 )?(count_ones(n/2, partial)):(count_ones(n/2, partial+1)); 
}

/**
  * @brief It counts the number of unique digits in a given base-10 number 
  */
unsigned int count( const unsigned int num, const unsigned int once=0, const unsigned int more=0 )
{
	if(num==0) return max(count_ones(once, 0), static_cast<unsigned int>(1)); 
	const auto d = num%10; ///< Just to make the code a bit more readable 
	
	if((once&(1<<d))==0 && (more&(1<<d))==0) return count(num/10, once|(1<<d), more); ///< New digit observed
	if((once&(1<<d))==(1<<d)) return count(num/10, once&(~(1<<d)), more|(1<<d)); ///< Reobservation of a unique digit
	else return count(num/10, once, more); ///< Reobservation of a non unique digit
}

int main() {
	// your code goes here
	cout << count(252) << endl;
	cout << count(25000) << endl; 
	cout << count(1234567890) << endl; 
	cout << count(0) << endl; 
	return 0;
}

