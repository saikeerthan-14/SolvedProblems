// class Solution {
// public:
//     int findPairs(vector<int>& nums, int k) {
//         unordered_set<int> s;
//         int ans = 0;
//         for(int i: nums) s.insert(i);
//         for(auto i = s.begin(); i != s.end(); i++) {
//             if(s.find(*i + k)!=s.end()) {
//                 ans++;
//             }
//             if(s.find(*i - k)!=s.end()) {
//                 ans++;
//             }
//             cout<<*i<<endl;
//             // s.erase(*i);
//         }
//         return ans;
//     }
// };
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int,int> a;
        for(int i:nums)
            a[i]++;
        int ans=0;
        for(auto x:a)
        {
            if(k==0)
            {    
                if(x.second>1)
                ans++;
            }
             else if(a.find(x.first+k)!=a.end())
                ans++;
        }
        
        return ans;
    }
};