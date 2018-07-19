
// Solution for 
// https://leetcode.com/problems/reverse-integer/description/

#include <algorithm>
#include <string>

class Solution {
public:
    int reverse(int x) {
        int sign=1; 
        if(x < 0) sign=-1; 
        auto temp1 = std::to_string(x); 
        std::reverse(temp1.begin(), temp1.end()); 
        long int temp=std::atol(temp1.c_str()); 
        if(temp > std::numeric_limits<int>::max()) return 0; 
        return sign*temp;  
    }
};


