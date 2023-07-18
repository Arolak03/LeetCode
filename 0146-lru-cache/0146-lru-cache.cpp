class LRUCache {
public:
    // keys k liye
    map<int, int> m;
    //address k liuye
    map<int,list<int>::iterator> address;
    //nodes insert delete
    list<int> l;
    int cap;
    //jitni max gh
    int size;
    // jitnme presently h
    LRUCache(int capacity) {
        cap=capacity;
        size=0;
        //initially
    }
    
    int get(int key) {
        // ab age key mile hi na
        if(m.find(key)==m.end()){
            return -1;
        }
        //mil jaaye to kaha milegi waha s hata kr front m daaln h
        list<int>::iterator it = address[key];
        //yaha s hatao l s hatao address s hatao
        l.erase(it);
        address.erase(key);
        //aage daalo
        l.push_front(key);
        address[key]=l.begin();
        return m[key];
    }
    
    void put(int key, int value) {
        //if old key already present then wo wali hataao
        if(m.find(key)!=m.end()){
            l.erase(address[key]);
            address.erase(key);
            m.erase(key);
            size--;
        }
        //ab jb puraani hatali to nyi daalo udhr
        //lekin agr capacity reached to last wali hatado
        if(cap==size){
            int k = l.back();
            l.pop_back();
            address.erase(k);
            m.erase(k);
            size--;
        }
        l.push_front(key);
        address[key]=l.begin();
        m[key]=value;
        size++;
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */