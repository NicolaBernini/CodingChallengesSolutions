/**
  * @brief Solution of the Exercise at Link1 
  * Link1 = https://leetcode.com/problems/two-sum/#/description
  */
#include <iostream>
#include <stdexcept>
#include <vector>
using namespace std;


/**
  * @brief Solution 
  * Predicate List 
  * p_pair_no_order = Computes all the possible pairs with no order distinction and no same element repetition, out of a list of elements 
  * p_criteria_sum_equal = It takes the final sum result as Param and checks it equals the result of sum applied to an element list (in this case a pair)
  * p_get_first = Takes the first element of a list 
  */

class Solution {
public:
    static vector<int> twoSum(vector<int>& nums, int target) {
        // pairs = map(p_pair_no_order, vector)
        // The full set of possibilities is given by a NxN Square Matrix and we are interested only in the upper/lower half matrix excluded the diagonal 
        for(int i=1; i<nums.size(); ++i)
        {
            for(int j=0; j<i; j++)
            {
                //// DEPRECATED 
            	////std::cout << "Checking i = " << i << ", j = " << j << " --> " << nums[i] << ", " << nums[j] << std::endl; 
                
                // The (i,j) is a valid pair 
                // result = map(p_get_first, filter( bind(p_criteria_sum_equal, target_val), pairs ) )
                if((nums[i] + nums[j]) == target) return std::vector<int>({j,i}); 
            }
        }
        
        // Get Here only if nothing has been found 
        //return std::vector<int>({0,0}); 
        throw std::out_of_range("No Element Pair Found"); 
    }
};

int main() {
	std::vector<int> temp = {2, 7, 11, 15}; 
	std::vector<int> res; 
	try
	{
		res = Solution::twoSum(temp, 26); 
	}
	catch(const std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl; 
	}

	std::cout << "Res = " << std::to_string(res[0]) << ", " << res[1] << std::endl; 
	// your code goes here
	return 0;
}
