class MyStack {
public:
    queue<int> q;
    MyStack() {
        
    }
//     1 2 3 - q
//     3 2 1 - st
//   1
//    1 2 ; 1 2 1; 2 1
//     2 1 3;   1 3 2;  3 2 1
    void push(int x) {
        q.push(x);
        for(int i=0;i<q.size()-1;i++) {
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() {
        int p = q.front();
        q.pop();
        return p;
    }
    
    int top() {
       return q.front(); 
    }
    
    bool empty() {
        return !q.size();
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