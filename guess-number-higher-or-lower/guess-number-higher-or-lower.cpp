/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int l = 1, h=n, m;
        while(true) {
            m = l + (h-l)/2;
            switch(guess(m)) {
                case 0: return m;
                    break;
                case 1: l = m+1;
                    break;
                case -1: h=m-1;
                    break;
            }
        }
        return n;
    }
};