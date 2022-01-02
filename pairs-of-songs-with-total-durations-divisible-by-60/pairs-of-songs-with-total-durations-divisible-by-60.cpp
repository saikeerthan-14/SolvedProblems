class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& t) {
        int ans = 0;
        vector<int> cnt(60, 0);
        for(int i=0;i<t.size();i++) {
            cnt[t[i]%60] ++;
        }
        for(int i=1;i<30;i++) {
            ans += cnt[i] * cnt[60-i];
        }
        return ans + ((cnt[0] *(cnt[0]-1))/2) + ((cnt[30]*(cnt[30]-1))/2);
    }
};

// [30,20,150,100,40]

// 30 - 2, 20 - 1, 40 - 2


// 2 + 
// (a+b)%c = ((a%c) + (b%c))%c


