# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def middleNode(self, head: ListNode | None) -> ListNode | None:
        size = 0
        curr = head
        while curr is not None:
            size += 1
            curr = curr.next

        curr = head
        for _ in range(size // 2):
            curr = curr.next

        return curr

# -------- SOLUTION BOUNDARY -------- #
class Solution:
    def middleNode(self, head: ListNode | None) -> ListNode | None:
        slow, fast = head, head
        while fast is not None and fast.next is not None:
            slow = slow.next
            fast = fast.next.next

        return slow
