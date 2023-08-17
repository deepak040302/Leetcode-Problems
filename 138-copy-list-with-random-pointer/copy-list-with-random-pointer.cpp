/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return head;
        Node* newlist = new Node(-1);
        Node* t = newlist , *tmp = head;
        map<Node*,Node*>mp;

        while(tmp!=NULL){
            Node* node  = new Node(tmp->val);
            Node* nxt = tmp->next;
            tmp->next = node;
            node ->next = nxt;
            tmp=nxt;
        }
        tmp=head;
        Node* anshead = head->next;

        while(tmp!=NULL){
            if(tmp->random==NULL){
                tmp->next->random=NULL;
            }else{
                tmp->next->random = tmp->random->next;
            }
            tmp=tmp->next->next;
        }

        tmp=head;
        while(tmp!=NULL){
            Node* t1 = tmp->next->next;
            if(t1==NULL){
                tmp->next->next=t1;
                tmp->next=t1;
            }else{
                tmp->next->next=t1->next;
                tmp->next=t1;
            }

            tmp = t1;
        }

        
        return anshead;;

    }
};