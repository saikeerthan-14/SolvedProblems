class Solution {
public:
    int minJumps(vector<int>& arr) {
        unordered_map<int,vector<int>>mp;
        int n=arr.size();
        for(int i=0;i<n;i++)
        {
            mp[arr[i]].push_back(i);
        }
        queue<int>q;
        vector<int>visited(n,0);
        int jump=0;
        q.push(0);
        visited[0]=1;
        while(!q.empty())
        {
            int x=q.size();
            while(x--)
            {
                int f=q.front();
                if(f==n-1)
                {
                    return jump;
                }
                q.pop();
                vector<int>temp=mp[arr[f]];
                for(int i=0;i<temp.size();i++)
                {
                    if(visited[temp[i]]==0)
                    {
                        q.push(temp[i]);
                        visited[temp[i]]=1;
                    }
                }
                mp.erase(arr[f]);
                if(f+1<n && visited[f+1]==0)
                {
                     q.push(f+1);
                    visited[f+1]=1;
                }
                if(f-1>=0 && visited[f-1]==0)
                {
                     q.push(f-1);
                    visited[f-1]=1;
                }
                temp.clear();
            }
            jump++;
        }
        return -1;
    }
};