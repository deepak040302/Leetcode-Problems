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
        Node* newlist = new Node(-1);
        Node* t = newlist , *tmp = head;
        map<Node*,Node*>mp;

        while(tmp!=NULL){
            t -> next = new Node(tmp->val);
            t = t -> next;
            mp[tmp] = t;
            tmp = tmp -> next;
        }

        tmp = head;
        Node *ptr = newlist->next;
        
        while(tmp!=NULL and ptr!=NULL){
            ptr->random = mp[tmp->random];
            tmp=tmp->next;
            ptr=ptr->next; 
        }

        return newlist->next;;

    }
};