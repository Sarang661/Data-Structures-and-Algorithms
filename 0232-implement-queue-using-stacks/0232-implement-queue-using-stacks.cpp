class MyQueue {
    stack<int>input;
    stack<int>output;
    
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        
        while(input.empty() == false){
            
            output.push(input.top());
            input.pop();
            
        }
        
        input.push(x);
        
           while(output.empty() == false){
            
            input.push(output.top());
           output.pop();
            
        }
        
        
    }
    
    int pop() {
        
        int val = input.top();
        input.pop();
        return val;
    }
    
    int peek() {
        
        return input.top();
    }
    
    bool empty() {
        
        return input.size() == 0;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */