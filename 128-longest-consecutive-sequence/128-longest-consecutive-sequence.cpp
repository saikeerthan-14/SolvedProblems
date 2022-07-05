class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int ans = 0;
        unordered_set<int>s;
        for(int i=0 ; i<nums.size() ; i++) {
            s.insert(nums[i]);
        }
        for(int i: nums) {
            if(s.find(i+1)==s.end()) {
                int c = 1, in = 1;
                while(s.find(i-in)!=s.end()) c++, in++;
                ans = max(ans, c);
            }
        }
        return ans;
    }
};