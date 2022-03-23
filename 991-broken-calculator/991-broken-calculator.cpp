class Solution {
public:
    int brokenCalc(int sv, int t) {
        int res = 0;
        while(t>sv) {
            if(t%2) t++;
            else t/=2;
            res++;
        }
        return res+sv-t;
    }
};