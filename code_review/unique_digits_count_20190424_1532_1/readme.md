
# Overview 

Count Unique Digits in a given number 

My posted solution [here](https://codereview.stackexchange.com/questions/216150/count-unique-digits-in-a-given-number/219022#219022)



# Post 

Here is my functional solution with improved space complexity based on bit manipulation 

Improvements 

- @Lundin has already identified major issues with the author's solution, my solution provides additional improvements which are related to 

- Space  

  - no need to count the actual number of times you observe a certain digit, just discriminate between 3 cases: never observed, observed once and observed more than once 

  - the `once` variable represents in its first 10 bits the digits that have been observed once 

  - the `more` variable represents in its first 10 bits the digits that have been observed more than once 

- Style 

  - This solution is Functional with all the related advantages (more readable, more concise, ...)


**EDIT**: My initial solution was in CPP so now I'm adding the C one: it is basically the same logic, all the CPP-specific stuff is not core 


## C Solution 

```c 
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

```

Output 

```
252 = 1
25000 = 2
1234567890 = 10
0 = 1

```


## CPP Solution 

```cpp
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

```

Output 

```
1
2
10
1
```



