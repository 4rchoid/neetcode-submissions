class MinStack {
private:
    vector<int> myStack{};
    vector<int> minStack{};

public:
    MinStack() {
    }
    
    void push(int val) {
        myStack.push_back(val);
        int interim{};
        if(minStack.size()>0){
            interim = minStack.back();
        }else{
            interim = myStack.back();
        }
        minStack.push_back(min(interim,val));
    }
    
    void pop() {
        myStack.pop_back();
        minStack.pop_back();
    }
    
    int top() {
        return myStack.back();
    }
    
    int getMin() {
        return minStack.back();
    }
};
