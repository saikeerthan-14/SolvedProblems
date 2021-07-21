class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int id1=-1, id2=-1;
        for(int i=0;i<n-1;i++){
            if(nums[i]<nums[i+1]) {
                id1 = i;
            }
        }
        if(id1!=-1){
            for(int i=0;i<n;i++) {
                if(nums[id1]<nums[i]){
                    id2 = i;
                }
            }
            swap(nums[id1], nums[id2]);
        }
        // cout<<id1<<" "<<id2;
        if(id1==-1) id1 = 0;
        else id1++;
        id2 = n-1;
        while(id1<=id2){
            swap(nums[id1++], nums[id2--]);
        }
    }
};