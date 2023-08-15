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
    ListNode* partition(ListNode* head, int x) {
        ListNode *l1=new ListNode(-1),*l2=new ListNode(-1),*ptr1=l1,*ptr2=l2;

        ListNode* tmp=head;

        while(tmp!=NULL){
            if(tmp->val < x){
                l1->next = new ListNode(tmp->val);
                l1=l1->next;
            }else{
                l2->next = new ListNode(tmp->val);
                l2=l2->next;
            }
            tmp=tmp->next;
        }
        l1->next = ptr2->next;
        return ptr1->next;

    }
};