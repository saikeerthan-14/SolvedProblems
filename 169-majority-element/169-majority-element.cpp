class Solution {
public:
   int majorityElement(vector<int>& nums) {
       int count=1,max_idx=0;
       for(int i=1;i<nums.size();i++) {
           if(nums[i]==nums[max_idx]) {
               count++;
           }
           else {
               count--;
           }
           if(count==0){
               max_idx=i;
               count=1;
           }
       }
       count=0;
       for(int i=0;i<nums.size();i++) {
           if(nums[i]==nums[max_idx]) {
               count++;
           }
       }
       if(count<=nums.size()/2) return -1;
         
       return nums[max_idx];  
   }
};