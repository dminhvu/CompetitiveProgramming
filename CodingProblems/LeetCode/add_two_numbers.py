# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        dHead = ListNode()
        answer = dHead
        r = 0
        while l1 != None or l2 != None:
            cur = 0
            if l1 != None:
                cur += l1.val
                l1 = l1.next
            if l2 != None:
                cur += l2.val
                l2 = l2.next
            cur += r
            answer.next = ListNode(cur % 10)
            answer = answer.next
            r = cur // 10
        if r > 0:
            answer.next = ListNode(r)
        return dHead.next