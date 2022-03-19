class FreqStack {
public:
    int max_freq = 0;
    unordered_map<int, int> freq;
    unordered_map<int, stack<int>>g;
    FreqStack() {
        
    }
    
    void push(int val) {
        freq[val]++;
        max_freq = max(max_freq, freq[val]);
        g[freq[val]].push(val);
    }
    
    int pop() {
        int t = g[max_freq].top();
        freq[t]--;
        g[max_freq].pop();
        if(g[max_freq].size()==0) max_freq--;
        return t;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */