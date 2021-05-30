# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def minDiffInBST(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        vals = []
        def dfs(node):
            if not node:
                return
            vals.append(node.val)
            dfs(node.left)
            dfs(node.right)
        dfs(root)
        vals.sort()
        return min([vals[i] - vals[i - 1] for i in range(1,len(vals))])
        
