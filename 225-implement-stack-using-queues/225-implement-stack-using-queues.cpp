class MyStack {
public:
    vector<int> v;
    int t=-1;
    MyStack() {
        
    }
    
    void push(int x) {
        v.push_back(x);
        t++;
    }
    
    int pop() {
        // if(t>-1) {
            int p = v[t];
            v.pop_back();
        t--;
            return p;
        // }
    }
    
    int top() {
        return v[t];
    }
    
    bool empty() {
        if(t<=-1) return true;
        return false;
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