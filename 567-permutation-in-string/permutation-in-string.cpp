class Solution {
public:
    void print(vector<int>&v) {
        for(int i=0;i<26;i++) {
            cout<<i<<" "<<v[i]<<";";
        }
        cout<<"\n";
    }
    bool checkInclusion(string s1, string s2) {
        vector<int>v(26, 0);
        for(int i=0;i<s1.size();i++) {
            v[s1[i]-'a']++;
        }
        if(s1.size()>s2.size()) return false;
        int i=0, j=0, total = s1.size();
        // print(v);
        while(j<s2.size()) {
            // cout<<"j: "<<j<<" i: "<<i<<" total "<<total<<"\n";
            if(v[s2[j]-'a']>0) {
                total--;
            }
            v[s2[j]-'a']--;
            j++;
            // print(v);
            if(total==0) return true;
            if(j-i==s1.size()) {
                if(v[s2[i]-'a']>=0)
                    total++;
                v[s2[i]-'a']++;
                i++;
                // print(v);
                // i++;
                // v[s2[i]-'a']++;
            }
            // j++;
        }
        return false;
        
    }
};