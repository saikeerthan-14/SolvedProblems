class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int>s;
        int ans = 0, w;
        for(int i=0; i<=heights.size();i++) {
            while(!s.empty() && (i==heights.size() || heights[s.top()]>=heights[i])) {
                int ele = heights[s.top()];
                s.pop();
                if(s.empty()) w=i;
                else w=i-s.top()-1;
                // cout<<ele<<" "<<w<<" "<<i<<endl;
                ans = max(ans, ele*w); 
            }
            s.push(i);
        }
        return ans;
    }
};