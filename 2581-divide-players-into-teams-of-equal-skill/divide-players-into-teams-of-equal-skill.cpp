class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(), skill.end());
        int i=0, j=skill.size()-1;
        long long p = 0;
        int match = skill[i] + skill[j];
        while(i<j) {
            if(skill[i]+skill[j] == match) {
                p += skill[i]*skill[j];
                i++;j--;
            } else {
                return -1;
            }
        }
        return p;
    }
};