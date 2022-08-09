class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        long long n=arr.size();
        long long mod=1e9+7;
        vector<int> ans(n, 1);
        sort(arr.begin(), arr.end());
        long long ans1=0;
        for(int i=0; i<n; i++){
            int in=0, en=i;
            int k=0;
            while(in<i && en>=0){
                if((long long)arr[in]*arr[en]==arr[i]){
                    long long k=(long long)ans[in]*ans[en]; k%=mod;
                    ans[i]+=k;
                    ans[i]%=mod;
                    in++; en--;
                }
                else if((long long)arr[in]*arr[en]>arr[i]){
                    en--;
                }
                else in++;
            } 
        }
        for(int i=0; i<n; i++){ 
            ans1+=ans[i];
            ans1%=mod;
        }
        return ans1;
    }
};
