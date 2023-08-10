/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverse(ListNode* curr,ListNode* nxt,ListNode* prev){
        if(curr==NULL) return prev;

        nxt = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = nxt;
        return reverse(curr,nxt,prev);
    }
    ListNode* reverseList(ListNode* head) {
        return reverse(head,NULL,NULL);
        
        ListNode* curr=head,*prev=NULL,*nxt=NULL;

        while(curr!=NULL){
            nxt = curr -> next;
            curr->next = prev;

            prev = curr;
            curr = nxt;

        }

        return prev;
    }
};