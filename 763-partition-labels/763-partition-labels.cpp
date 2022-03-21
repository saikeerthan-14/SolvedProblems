class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> ans, v(26, 0);
        int s1=0, e = 0;
        for(int i=0;i<s.size();i++) v[s[i]-'a'] = i;
        for(int i=0;i<s.size();i++) {
            e = max(e, v[s[i]-'a']);
            if(i==e) {
                ans.push_back(e-s1+1);
                s1 = i+1;
            }
        }
        return ans;
        
    }
};