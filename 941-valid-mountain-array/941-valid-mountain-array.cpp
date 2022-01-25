class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int n=arr.size();
        if(n<3) return false;
        int i;
        for(i=0;i<n-1 && arr[i]<arr[i+1];i++);
        if(i==n-1 || i==0) return false;
        for(;i<n-1 && arr[i]>arr[i+1];i++);
        if(i==n-1) return true;
        return false;
    }
};