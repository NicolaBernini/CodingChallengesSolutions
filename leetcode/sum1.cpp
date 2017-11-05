/**
  * @brief Solution of the Exercise at Link1 
  * Src Link1 = https://leetcode.com/problems/two-sum/#/description
  * Working on = https://leetcode.com/submissions/detail/126875783/
  * See it running 
  * https://ideone.com/JHG6om
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
    // Brute Force Solution 
    // TC: O(n^2), SC: O(1)
    static vector<int> twoSum(const vector<int>& nums, const int target) 
    {
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
	
    // Hashing Solution 
    // TC: O(n), SC: O(n)
    static vector<int> twoSum_HashMap(const vector<int>& nums, const int target)
    {
        std::map<int, int> t_hash_map; 
        
        // hash_list = map(p_hash_transform, map(p_pair, nums, map(p_index, nums) ) )
        for(int i=0; i<nums.size(); ++i) t_hash_map.insert(std::pair<int,int>(nums[i],i)); 
        
        // valid_pair = map(p_get_first, filter( bind(p_sum_equal, hash_list, target), nums) )
        std::map<int,int>::iterator it; 
        for(int i=0; i<nums.size(); ++i) 
            if((it=t_hash_map.find(target-nums[i]) ) != t_hash_map.end() &&     // Find first element that is paired 
               (it->second != i)                                                // Check it is not the same element, as it is not allowed 
              ) return std::vector<int>({i, it->second}); 
        throw std::out_of_range("No Element Pair Found"); 
    }    

};

int main() {
	std::vector<int> temp = {2, 7, 11, 15}; 
	std::vector<int> res1, res3; 
	try
	{
		res1 = Solution::twoSum(temp, 26); 
		res3 = Solution::twoSum_HashMap(temp, 26); 
	}
	catch(const std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl; 
	}

	std::cout << "Res1 = " << std::to_string(res1[0]) << ", " << res1[1] << std::endl; 
	std::cout << "Res3 = " << std::to_string(res3[0]) << ", " << res3[1] << std::endl; 
	// your code goes here
	return 0;
}
