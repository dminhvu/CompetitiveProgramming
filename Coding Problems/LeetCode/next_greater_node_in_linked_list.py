# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def nextLargerNodes(self, head):
        """
        :type head: ListNode
        :rtype: List[int]
        """
        ans = []
        a = []
        def get_a(head):
            if head == None:
                return
            a.append(head.val)
            get_a(head.next)
        get_a(head)
        a.reverse()
        st = []
        for i in range(len(a)):
            while len(st) > 0 and a[i] >= st[-1]:
                st.pop(-1)
            if len(st) == 0:
                ans.append(0)
            elif a[i] < st[-1]:
                ans.append(st[-1])
            st.append(a[i])
        return reversed(ans)
