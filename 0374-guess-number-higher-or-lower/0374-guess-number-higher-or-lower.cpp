/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int solve(int start, int end)
    {
        int mid = start+ (end-start)/2;

        if(guess(mid)==0)
            return mid;
        
        else if(guess(mid)==-1)
            return solve(start, mid-1);
        
        else
            return solve(mid+1, end);
    }

    int guessNumber(int n) {
        int start = 1;
        int end = n;
        return solve(start, end);
    }
};