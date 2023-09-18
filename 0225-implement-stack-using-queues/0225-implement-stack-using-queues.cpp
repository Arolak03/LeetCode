class MyStack {
public:
    queue<int> q1;
    queue<int> q2;
    bool bool1=true;
    bool bool2=true;
    MyStack() {
        
    }
    
    void push(int x) {
        if(bool2)
            q1.push(x);
        else{
            q2.push(x);
        }
        
    }
    
    int top() {
        if(bool2){
        while(q1.size()>1){
            q2.push(q1.front());
            q1.pop();
        }
            bool1=false;
            return q1.front();
            
        }
        else{
            while(q2.size()>1){
            q1.push(q2.front());
            q2.pop();
        }
            bool1=true;
            return q2.front();
        }
    }
    
    int pop() {
        if(bool2){
        while(q1.size()>1){
            q2.push(q1.front());
            q1.pop();
        }
            bool2=false;
            int n = q1.front();
            q1.pop();
            return n;
            
        }
        else{
            while(q2.size()>1){
            q1.push(q2.front());
            q2.pop();
        }
            bool2=true;
            int n = q2.front();
            q2.pop();
            return n;
            
        }
    }
    
    bool empty() {
        if(q1.size()+q2.size()!=0){
            return false;
        }
        return true;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */