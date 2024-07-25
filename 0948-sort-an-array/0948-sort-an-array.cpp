class Solution {
public:
    void merge(vector<int>& nums, int l, int h) {
        if(l>=h) {
            return;
        }
            int m = l + (h-l)/2;
            merge(nums, l, m);
            merge(nums, m+1, h);
            mergeSort(nums, l, m, h);
    }

    void mergeSort(vector<int>& nums, int l, int m, int h) {
        int i = l, j = m+1;
        vector<int> v;
        while(i<=m && j<=h) {
            if(nums[i]<nums[j]) {
                v.push_back(nums[i]);
                i++;
            } else {
                v.push_back(nums[j]);
                j++;
            }
        }
        while(i<=m) {
            v.push_back(nums[i]);
            i++;
        }
        while(j<=h) {
            v.push_back(nums[j]);
            j++;
        }
        for(int i =0;i<v.size();i++) {
            // cout<<v[i]<<" ";
            nums[l+i] = v[i];
        }
        // cout<<endl;
    }

    vector<int> sortArray(vector<int>& nums) {
        int l = 0, h = nums.size()-1;
        merge(nums, l, h);
        return nums;
    }
};