class StockSpanner {
public:
    stack<pair<int,int>>s;
    StockSpanner() {
    }
    
    int next(int price) {
        int x=1;
        while(!s.empty() and s.top().first<=price)
        {
            x+=s.top().second;
            s.pop();
        }
        s.push({price,x});
        return x;
    }
};
/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */