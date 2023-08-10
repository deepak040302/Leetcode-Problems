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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* curr=head;

        while(curr->next!=NULL){
            int a = curr -> val;
            int b = curr -> next -> val;
            int gcd = __gcd(a,b);

            ListNode* temp = curr->next;
            ListNode* nn =new ListNode(gcd);
            nn -> next = curr -> next;
            curr -> next = nn;

            curr = temp;    
        }

        return head;
    }
};