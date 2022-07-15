class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int maxarea = 0;
        int dx[4] = {-1,0,1,0};
        int dy[4] = {0,1,0,-1};
		
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(grid[i][j]==1){
                    int currarea = 0;
                    queue<pair<int,int>> q;
                    grid[i][j] = 0;
                    q.push({i,j});
					
                    while(!q.empty()){
                        int x = q.front().first;
                        int y = q.front().second;
                        currarea++;
                        q.pop();
                        for(int k = 0;k<4;k++){
                            int newx = x + dx[k];
                            int newy = y + dy[k];
                            if(newx>=0 && newx<m && newy>=0 && newy<n && grid[newx][newy]==1){
                                q.push({newx,newy});
                                grid[newx][newy] = 0;
                            }
                        }
                    }
					
                    maxarea = max(maxarea,currarea); 
                }
            }
        }
        return maxarea;
    }
};