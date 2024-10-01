class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        vector<int> v(k, 0);
        int j;
        for(int i=0;i<arr.size();i++) {
            j = arr[i]%k;
            if(j<0) j+=k;
            v[j]++;
        }
        for(int i=1;i<((k/2)+1);i++) {
            if((i!=k-i && v[i]!=v[k-i]) || (i==k-i && v[i]%2!=0)) return false;
        }
        return true;
    }
};