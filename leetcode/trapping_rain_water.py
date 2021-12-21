# Link
# https://leetcode.com/problems/trapping-rain-water/submissions/

# Solution 1
# Time: O(N) and Space O(N)
class Solution:
    def trap(self, height: List[int]) -> int:
        
        left = [None] * len(height)
        right = [None] * len(height)
        
        top = 0
        for i in range(len(height)):
            left[i] = top
            top = max(top, height[i])
            
        top = 0
        for i in range(len(height)):
            right[len(height)-i-1] = top
            top = max(top, height[len(height)-i-1])
        
        res = 0
        for i in range(len(height)):
            print("")
            res += max(min(left[i], right[i]) - height[i], 0)
            
        return res

      
      

