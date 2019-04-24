#include <stdio.h>

/**
  * @brief It just counts the number of 1s in a given binary representation 
  */
unsigned int count_ones(const unsigned int n, const unsigned int partial)
{
	if(n==0) return partial; 
	return ( (n&1)==0 )?(count_ones(n/2, partial)):(count_ones(n/2, partial+1)); 
}

/**
  * @brief It counts the number of unique digits in a given base-10 number 
  */
unsigned int count( const unsigned int num, const unsigned int once, const unsigned int more )
{
	if(num==0) return (count_ones(once, 0)>0)?(count_ones(once, 0)):1;  
	const unsigned int d = num%10; ///< Just to make the code a bit more readable 
	
	if((once&(1<<d))==0 && (more&(1<<d))==0) return count(num/10, once|(1<<d), more); ///< New digit observed
	if((once&(1<<d))==(1<<d)) return count(num/10, once&(~(1<<d)), more|(1<<d)); ///< Reobservation of a unique digit
	else return count(num/10, once, more); ///< Reobservation of a non unique digit
}


int main(void) {
	// your code goes here
	printf("252 = %d\n", count(252,0,0));
	printf("25000 = %d\n", count(25000,0,0)); 
	printf("1234567890 = %d\n", count(1234567890, 0, 0)); 
	printf("0 = %d\n", count(0,0,0)); 
	return 0;
}




