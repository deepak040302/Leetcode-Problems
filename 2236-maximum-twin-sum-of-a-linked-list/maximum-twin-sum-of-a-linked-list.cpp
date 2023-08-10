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
    int pairSum(ListNode* head) {
        ListNode* tmp = head;
        int len =0;
        while(tmp){len+=1,tmp=tmp->next;}

        tmp = head;
        stack<int>st;
        int ans=0;

        for(int i=0;i<len;i++){
            if(i>=len/2){
                ans=max(ans,st.top()+tmp->val);
                st.pop();
            }else{
                st.push(tmp->val);
            }
            tmp=tmp->next;
        }

        return ans;
    }
};