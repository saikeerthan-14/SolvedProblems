class Solution {
public:
    int dfs(vector<vector<int>>& stones, vector<bool> & visited, int index){
        int res=1;
        for(int i=0;i<stones.size();i++){
            if(!visited[i] and ((stones[i][0] == stones[index][0]) or (stones[i][1] == stones[index][1]))){
                visited[i]=true;
                res+= dfs(stones, visited, i);
            }
        }
        return res;
    }

    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        int res=0;
        vector<bool>visited(n);
        for(int i=0;i<n;i++){
            if(!visited[i]){
                visited[i]=true;
                res+=(dfs(stones, visited, i) -1);
            }
        }
        return res;
    }
};