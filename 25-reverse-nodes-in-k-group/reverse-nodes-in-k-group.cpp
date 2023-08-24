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
    int length(ListNode* head){
        int ct=0;
        ListNode* temp=head;
        while(temp!=NULL) {
            ct+=1;
            temp=temp->next;
        }
        return ct;
    }


    ListNode* reverseKGroup(ListNode* head, int k) {

        if(head==NULL) return NULL;
        ListNode* curr=head,*prev=NULL,*nxt=NULL;

        int nl = length(head);
        if(nl>=k){
            int i=0;
            while(i<k and curr!=NULL){
                cout<<curr->val<<endl;
                nxt = curr -> next;
                curr->next=prev;

                prev=curr;
                curr=nxt;
                i++;
            }
            head->next = reverseKGroup(curr,k);
        }else{
            return head;
        }


        return prev;
    }
};