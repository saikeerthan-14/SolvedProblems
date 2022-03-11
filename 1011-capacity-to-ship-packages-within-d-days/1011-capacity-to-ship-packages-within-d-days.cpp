class Solution {
public:
    
    bool isValid(vector<int>&w, int cap, int days) {
        int cnt = 1, ws=0;
        for(int i=0;i<w.size();i++) {
            if(w[i]>cap) return false;
            if(ws+w[i] <=cap) {
                ws += w[i];
            } else {
                ws = w[i];
                cnt++;
            }
            if(cnt>days) return false;
        }
        return true;
    }
    
    int shipWithinDays(vector<int>& w, int days) {
        int l = w[0], h = 0, n = w.size();
        for(int i: w) h+=i;
        while(l<h) {
            int m = l + (h-l)/2;
            if(isValid(w, m, days)) {
                h = m;
            } else {
                l = m+1;
            }
        }
        return l;
    }
};