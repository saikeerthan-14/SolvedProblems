class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int a = 0, b = 0, i = 0, j = piles.size()-1, c = 0;
        while(i<=j) {
            if(piles[i]>=piles[j]) {
                if(c%2==0) a+= piles[i];
                else b += piles[i];
                i++; 
            } else {
                if(c%2==0) a+= piles[j];
                else b += piles[j];
                j--;
            }
        }
        return a>b;
    }
};