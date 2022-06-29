class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        int n = people.size();
        sort(people.begin(),people.end());
        vector<vector<int>> ans(n) ;
        for(int i = 0; i < n; i++){
            vector<int>v = {-1,-1};
            ans[i] = v;
        }
        for(int i = 0 ; i < n;i++){
          vector<int>p = people[i];
          int position = people[i][1];  
          for(int  j = 0 ; j < n; j++){
              if(position == 0 && ans[j][0] == -1)
              {
                  ans[j] = people[i];
                  break;
              }
              else if(position != 0 && (ans[j][0] >= people[i][0] || ans[j][0] == -1)){
                  position--;
              }
              
          }
        }
        return ans;
    }
};