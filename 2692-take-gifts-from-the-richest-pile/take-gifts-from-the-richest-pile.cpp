class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> pq(gifts.begin(), gifts.end());
        while(k--) {
            int top = sqrt(pq.top());
            pq.pop();
            pq.push(top);
        }
        long long ans = 0;
        while(!pq.empty()) {
            ans += pq.top();
            pq.pop();
        }
        return ans;
    }
};