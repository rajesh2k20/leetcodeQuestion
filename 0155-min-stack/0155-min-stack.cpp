class MinStack {
public:
    
    stack<long long > s;
    
    int minval;
    
    MinStack() {
        
        minval=-1e9;
        
    }
    
    void push(int val) {
        
        if(s.size()==0){
            
            s.push(val);
            minval=val;
        }else{
            
            if(val>=minval){
                s.push(val);
            }else{
               long long  corrupt= 1LL*val+(1LL*val-1LL*minval);
                minval=val;
                s.push(corrupt);
            }
        }
        
    }
    
    void pop() {
        
        if(s.size()==0){
            return;
        }else{
            
            if(s.top()< minval){
                
             long long  premin= 1LL*2*minval-s.top();
              minval=premin;
              
            }
            
            s.pop();
        }
        
    }
    
    int top() {
        
        if(s.size()==0){
             return 0;
        }
        
        if(s.top()<minval){
            
            return minval;
        }else{
             return s.top();
        }
        
    }
    
    int getMin() {
        
        
      return minval;
        
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