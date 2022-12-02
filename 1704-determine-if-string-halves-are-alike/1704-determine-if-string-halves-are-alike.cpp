class Solution {
public:
    
    bool halvesAreAlike(string s) {
        
        int n = s.length()  , left = 0 , right = 0  , i = 0 ; 
        int j = n/2 ;   // Half the size of string for two pointer approch .
        
        string vw = "aeiouAEIOU" ; 
        
        // A map to check for Vowels
        map<int , int > mp ;
        for(auto y : vw) mp[y]++;
        
        while(i < n/2 )
        {
            if(mp.find(s[i]) != mp.end())left++ ; 
            if(mp.find(s[i+j]) != mp.end())right++;
            i++; 
        }
        
        if(left == right) return true ;
        else return false ;
    }
};
