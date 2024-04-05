class Solution {
public:
    string makeGood(string s) {
        	int n = s.size();
	int i = 0;        
    
    while(i<n-1)
    {
		// comparing the adjacent characters by converting the uppercase to lowercase and the same adjacent characters should be removed 
		// For Example, LeEeetcode 'eE' or 'Ee' should be removed but not 'ee'.  
        if((tolower(s[i]) == s[i+1] or s[i] == tolower(s[i+1])) and s[i] != s[i+1])
        {
			// removes substring starting from index i to length of 2.
            s.erase(i,2);
            
            if(i > 0)
            {
                i = i - 1;
            }
        }
        else
        {
            i++;
        }
    }
    
    return s;
}
    
};