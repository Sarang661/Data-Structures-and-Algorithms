class MinStack {
    
    stack<int>st;
    stack<int>temp;
    
public:
    MinStack() {
        
    }
    
    void push(int val) {
    st.push(val);
    
        if(temp.size() > 0 && temp.top() >= val){
            temp.push(val);
        }
        
          if(temp.size() == 0){
            temp.push(val);
        }
        
    }
    
    void pop() {
        
        if(st.top() == temp.top()){
            temp.pop();
            st.pop();
        }
        else{
            st.pop();
        }
    }
    
    int top() {
        
        return st.top();
    }
    
    int getMin() {
        
        return temp.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */