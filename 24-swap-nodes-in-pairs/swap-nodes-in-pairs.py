# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def swapPairs(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if not head or not head.next:
            return head

        sec=head.next
        third=sec.next

        head.next = third
        sec.next = head

        if(third and third.next):
            head.next = self.swapPairs(third)
        
        return sec