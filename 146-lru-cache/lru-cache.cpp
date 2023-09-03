class Node{
public:
    int val,key;
    Node *next,*prev;

    Node(int val,int key){
        this->val = val;
        this->key = key;
        this->next = NULL;
        this->prev = NULL;
    }
};


Node* insert_at_head(Node* head,int val,int key){
    Node* forward = head->next;
    Node* tmp = new Node(val,key);

    head->next=tmp;
    forward->prev=tmp;
    tmp->next=forward;
    tmp->prev=head;

    return head;
}

Node* delete_node(Node* head,Node* del){
    Node* forward = del->next;

    forward->prev=del->prev;
    forward->prev->next=forward;
    delete(del);

    return head;
}

class LRUCache {
private:
    int sz=0;
    int cap;
    unordered_map<int,Node*>mp;

    //made the list
    Node *head = new Node(-1,-1),*tail=new Node(-1,-1);


public:
    LRUCache(int capacity) {
        head->next=tail;
        tail->prev=head;
        cap = capacity;
    }
    
    int get(int key) {
        if(mp.count(key)){
            int val =  mp[key]->val;
            head = delete_node(head,mp[key]);
            head = insert_at_head(head,val,key);
            Node* ref = head->next;
            mp[key]=ref;
            return val;
        }
        return -1; 
    }
    
    void put(int key, int value) {
        if(mp.count(key)){
            head = delete_node(head,mp[key]);
            head = insert_at_head(head,value,key);
            Node* ref = head->next;
            mp[key]=ref;
        }else{
            if(sz==cap){
                mp.erase(tail->prev->key);
                head = delete_node(head,tail->prev);
                head = insert_at_head(head,value,key);
                mp[key]=head->next;
            }else{
                head = insert_at_head(head,value,key);
                mp[key]=head->next;
                sz+=1;
            }
        }

    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */