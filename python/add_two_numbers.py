# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        carry = 0
        head = None
        cur = None
        v1 = 0
        v2 = 0
        while None != l1 or None != l2 or 0 != carry:
            if None != l1:
                v1 = l1.val
            else:
                v1 = 0
                
            if None != l2:
                v2 = l2.val
            else:
                v2 = 0
            sum = v1 + v2 + carry;
            carry = sum / 10;
            if None == head:
                head = ListNode(sum%10)
                cur = head
            else:
                cur.next = ListNode(sum%10)
                cur = cur.next
                
            if None != l1:
                l1 = l1.next
            else:
                l1 = None
                
            if None != l2:
                l2 = l2.next
            else:
                l2 = None
        return head