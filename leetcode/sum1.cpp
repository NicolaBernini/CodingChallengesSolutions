/**
  * @brief Solution of the Exercise at Link1 
  * Link1 = https://leetcode.com/problems/two-sum/#/description
  */
#include <iostream>
#include <stdexcept>
#include <vector>
using namespace std;


class Solution {
public:
    static vector<int> twoSum(vector<int>& nums, int target) {
        for(int i=1; i<nums.size(); ++i)
        {
            for(int j=0; j<i; j++)
            {
            	//std::cout << "Checking i = " << i << ", j = " << j << " --> " << nums[i] << ", " << nums[j] << std::endl; 
                if((nums[i] + nums[j]) == target) return std::vector<int>({i,j}); 
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
