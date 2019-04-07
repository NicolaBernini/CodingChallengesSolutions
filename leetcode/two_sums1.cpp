
// Original Link 
// https://leetcode.com/problems/two-sum/submissions/

#include <unordered_map>

/**
  * @brief The Solution to the following problem: given an Array of N integers and a target number, return the indexes of the 2 elements which summed give the target value 
  * @note Ideas 
  * 1. Invest O(N) to build an HashMap connecting each new observed value to its position 
  * 2. If a value is repeated at least once, store this into a separate map and ignore any further occurrence of the same value as it is not relevant from an Algo perspective 
  * 3. Perform another O(N) loop on the HashMap and for each value perform an O(1) Lookup to check the presence of the corresponding value which summed can give the desired target value 
  */
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> data; 
        unordered_map<int, int> multiple; 
        
        for(int i=0; i<nums.size(); ++i) 
        {
            const auto n = nums[i]; 
            if(data.find(n) == data.end()) data[ n ] = i; 
            else multiple[n] = i; 
        }
            
        for(auto i=data.begin(); i != data.end(); ++i) 
        {
            const auto n = i->first; 
            const auto diff = target - n; 
            if(diff == n) 
            {
                auto j = multiple.find(n); 
                if(j != multiple.end()) return {i->second, j->second}; 
            }
            else 
            {
                auto j = data.find(diff); 
                if(j != data.end()) return {i->second, j->second};                 
            }
        }
        return {0,0}; 
    }
};








