class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        size_t prev=0,maxd=0;
        for(size_t i=0; i<seats.size(); ++i) {
            if(!seats[i]) continue;
            maxd=!prev and !seats[0]?max(maxd,i-prev):max(maxd,(i-prev)/2);
            prev=i;
        }
        return max(maxd,seats.size()-1-prev);
    }
};