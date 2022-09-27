class Solution {
public:
    string pushDominoes(string d) {
        int n = d.size();
        int curr = 0, l=-1;
        char prev = 'L';
        while(curr<n) {
            if(d[curr] !='.') {
                if(d[curr]=='L') {
                    if(prev=='L') {
                        for(int i= l+1;i<curr;i++) d[i] = 'L';
                    } else {
                        int p1= l+1, p2 = curr-1;
                        while(p1<p2) {
                            d[p1++] = 'R';
                            d[p2--] = 'L';
                        }
                    }
                    prev = 'L';
                    // l = curr;
                } else {
                    if(prev=='R') {
                        for(int i= l+1;i<curr;i++) d[i] = 'R';
                    }
                    prev = 'R';
                    // l = curr;
                }
                l = curr;
                // curr++;
            }
            curr++;
        }
        if(prev=='R') {
                for(int i= l+1;i<curr;i++) d[i] = 'R';        
        }
        return d;
    }
};