class Solution {
public:
    bool dfs(vector<int>& matchsticks, vector<int>& sides, int index, int target){
        if(index == -1){
            return true;
        }
        for(int i = 0; i < 4; i++){
            if(((sides[i] + matchsticks[index]) > target) or (i > 0 and sides[i] == sides[i - 1])){
                continue;
            }
            sides[i] += matchsticks[index];
            if(dfs(matchsticks, sides, index - 1, target)){
                return true;
            } 
            sides[i] -= matchsticks[index];
        }
        return false;
    }
    
    bool makesquare(vector<int>& matchsticks) {
        int sum = 0;
        for(int i : matchsticks){
            sum += i;
        }
        if(sum%4 != 0 or matchsticks.size() < 3){
            return false;
        }
        sort(matchsticks.begin(), matchsticks.end());
        vector<int> sides(4, 0);
        return dfs(matchsticks, sides, matchsticks.size() - 1, sum/4);
    }
};