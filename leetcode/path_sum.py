# Link
# https://leetcode.com/problems/path-sum/submissions/
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def hasPathSum(self, root: Optional[TreeNode], targetSum: int) -> bool:
        if root is None:
            return False
        if targetSum - root.val == 0 and root.left is None and root.right is None:
            return True
        
        left = self.hasPathSum(root.left, targetSum - root.val) if root.left is not None else False
        
        right = self.hasPathSum(root.right, targetSum - root.val) if root.right is not None else False
        
        
        
        return left or right


      
