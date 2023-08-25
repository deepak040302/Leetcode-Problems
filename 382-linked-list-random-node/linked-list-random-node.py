# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
import random

class Solution:

    def __init__(self, head: Optional[ListNode]):
        self.lst = []
        tmp = head
        while tmp is not None:
            self.lst.append(tmp.val)
            tmp = tmp.next

    def getRandom(self) -> int:
        return self.lst[random.randint(0, len(self.lst) - 1)]




# Your Solution object will be instantiated and called as such:
# obj = Solution(head)
# param_1 = obj.getRandom()