class LRUCache {
    
    class Node{
        public:
        int key;
        int value;
        Node*next;
        Node*prev;
        
        Node(int key, int value){
            
            this->key = key;
            this->value = value;
        }
    };
    
    Node*head = new Node(-1,-1);
    Node*tail = new Node(-1,-1);
    int cap = 0;
    map<int,Node*>val;
    
public:
    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    void removeNode(Node*node){
        cap++;
        Node*prev = node->prev;
        Node*next = node->next;
        prev->next = next;
        next->prev = prev;
    }
    
    Node*addNode(Node*node){
        cap--;
        Node*curr = head->next;
        head->next = node;
        node->prev = head;
        curr->prev = node;
        node->next = curr;
        
        return node;
    }
    int get(int key) {
        
        if(val.find(key)==val.end()){
            return -1;
        }
        
        removeNode(val[key]);
        
        val[key] = addNode(new Node(key, val[key]->value));
        
        return val[key]->value;
    }
    
    void put(int key, int value) {
        
        
        if(val.find(key)!=val.end()){
            removeNode(val[key]);
            val.erase(key);
        }
        
         if(cap == 0){
            
            val.erase(tail->prev->key);
            removeNode(tail->prev);
            
        }
        
        val[key] = addNode(new Node(key, value));
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */