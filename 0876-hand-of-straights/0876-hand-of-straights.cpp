class Solution {
public:
    bool isNStraightHand(vector<int>& nums, int gs) {
        int n = nums.size();
        if(n%gs) return false;
        if(gs==1) return true;
        // priority_queue<int> pq;
        // unordered_map<int, int> u;
        map<int, int> u;
        for(int i=0;i<nums.size();i++) {
            // pq.push(nums[i]);
            u[nums[i]]++;
        }
        // int f, s;
        // while(!pq.empty()) {
        //     f = pq.top();
        //     for(int i=1;i<gs;i++) {
        //         // s = pq.top();
        //         // pq.pop();
        //         u[f]--;
        //         if(u[f]==0) u.erase(f);
        //         f--;
        //         if(u.find(f)==u.end()) return false;
        //     }
        //     pq.pop();

        //     cout<<"---"<<endl;
        // }
        while(!u.empty()) {
            int cnt = 0;

            for(auto i: u) {
                int k = i.first;
                // cout<<cnt<<" "<<k<<" "<<u[k]<<endl;
                
                u[k]--;
                if(u[k]==0) u.erase(k);
                k++;
                cnt++;
                while(u.find(k)!=u.end()) {
                    // cout<<cnt<<" "<<k<<" "<<u[k]<<endl;
                    
                    u[k]--;
                    if(u[k]==0) u.erase(k);
                    k++;
                    cnt++;
                    if(cnt==gs)
                        break;
                }
                // cout<<"---"<<endl;
                if(cnt!=gs) return false; 
                else break;
            }
        }
        return true;
    }
};