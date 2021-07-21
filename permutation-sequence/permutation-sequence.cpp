class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> a;
        int fact = 1;
        for(int i=1;i<n;i++) {
            fact *= i;
            a.push_back(i);
        }
        a.push_back(n);
        k--;
        // n--;
        // k%=fact;
        string ans="";
        while(true) {
            ans += a[k/fact] + '0';
            a.erase(a.begin()+k/fact);
            n--;
            if(n==0) break;
            k = k%fact;
            fact /= n;
        }
        return ans;
    }
};