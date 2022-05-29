class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size();
        vector<int> c(n);
        int mx = 0;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<(int)words[i].size(); j++)
                c[i] |= 1<<(words[i][j] - 'a');
            for(int j = 0; j<i; j++){
                if((c[i] & c[j]) == 0){
                    mx = max(mx,(int)words[i].size()*(int)words[j].size());
                }
            }
        }
        
        return mx;
    }
};