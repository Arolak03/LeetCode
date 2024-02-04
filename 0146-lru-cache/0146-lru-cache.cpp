class LRUCache {
public:
    
    struct ListNode{
        ListNode* prev;
        ListNode* next;
        int data;
        int key;
        ListNode(int key, int data) {
            this->key = key;
            this->data = data;
            prev = NULL;
            next = NULL;
        }

    };
    ListNode* head;
    ListNode*tail;
    unordered_map<int,ListNode*> mpp;
    int k;
    void moveToHead(ListNode* node){
        if(node==head)return;
        if(node==tail){
            tail=tail->prev;
            tail->next=NULL;
        }
        else{
            node->prev->next=node->next;
            node->next->prev=node->prev;
        }
        node->next=head;
        head->prev=node;
        head=node;
        node->prev=NULL;
    }
    LRUCache(int capacity) {
        k=capacity;
        head=NULL;
        tail=NULL;
    }
    
    
    int get(int key) {
        if(mpp.find(key)!=mpp.end()){
            ListNode* curr=mpp[key];
            moveToHead(curr);
            return curr->data;
        }
       else{
           return -1;
       }
    }
    
    void put(int key, int value) {
    if (mpp.find(key) != mpp.end()) {
        ListNode* curr = mpp[key];
        curr->data = value;
        moveToHead(curr);
    } else {
        ListNode* temp = new ListNode(key, value);
        if (mpp.size() >= k) {
            mpp.erase(tail->key);
            if (tail->prev) {
                tail = tail->prev;
                tail->next = NULL;
            } else {
                head = tail = NULL;
            }
        }
        mpp[key] = temp;
        if (!head) {
            head = tail = temp;
        } else {
            temp->next = head;
            head->prev = temp;
            head = temp;
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