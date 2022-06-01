class Solution {
public:
    bool hasAllCodes(string s, int k) {
        if (s.length()<k)
            return false;
        unordered_set<string> hashset;
        bool ans = false;
        int i=0;
        int j=k-1;
        
        while (j<s.length()) {
            // cout << "i:" << i << ", j:" << j << endl;
            // cout << s.substr(i,k) << endl;
            hashset.insert (s.substr(i,k));
            i++, j++;
        }
        return hashset.size()==pow(2,k);
    }
};