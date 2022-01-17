class Solution {
    public int[] shuffle(int[] nums, int n) {
        if(n==0){
            return nums;
        }
       else{
           int arr[]=new int[nums.length];
           int j=0;
           for(int i=0;i<nums.length && j<nums.length;i++){
               arr[j]=nums[i];
               j++;
               arr[j]=nums[i+n];
               j++;
           }
           return arr;
           
       }        
        
    }
}