class Solution {
public:
    bool check(int x,int y,int n){
        return (x>=0 && x<n && y>=0 && y<n);
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        if(grid[0][0]!=0 || grid[n-1][n-1]!=0) return -1;
        queue<pair<int,int>> q;
        int dx[8]={-1,1,0,0,-1,-1,1,1};
        int dy[8]={0,0,1,-1,1,-1,1,-1};
        grid[0][0]=1;
        q.push({0,0});
        while(!q.empty()){
            auto curr=q.front();
            q.pop();
            int x=curr.first,y=curr.second;
            if(x==n-1 && y==n-1) return grid[x][y];
            for(int i=0;i<8;i++){
                int X=x+dx[i],Y=y+dy[i];
                if(check(X,Y,n) && grid[X][Y]==0){
                    grid[X][Y]=1+grid[x][y];
                    q.push({X,Y});
                }
            }
        }
        return -1;
    }
};