# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def goodNodes(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        def dfs(node,max_val):
            if node == None:
                return 0
            cnt = node.val >= max_val
            cnt += dfs(node.left,max(max_val,node.val))
            cnt += dfs(node.right,max(max_val,node.val))
            return cnt
        return dfs(root,-10**5)
        
