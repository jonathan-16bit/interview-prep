# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeNthFromEnd(self, head: ListNode | None, n: int) -> ListNode | None:
        sz = 0
        curr = head
        while curr is not None:
            sz += 1
            curr = curr.next

        if n == sz:
            return head.next

        count = 1
        curr = head
        while count < sz - n:
            curr = curr.next
            count += 1
            
        if n == 1:
            curr.next = None
        else:
            curr.next = curr.next.next

        return head
