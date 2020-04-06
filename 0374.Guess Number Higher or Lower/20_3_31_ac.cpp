# include <iostream>

using namespace std;

class Solution {
public:
    /** 
     * Forward declaration of guess API.
     * @param  num   your guess
     * @return 	     -1 if num is lower than the guess number
     *			      1 if num is higher than the guess number
    *               otherwise return 0
    * int guess(int num);
    */
    int guess(int num);

    int guessNumber(int n) {
        int left = 1, right = n, mid, res;
        while(left <= right){
            mid = left + (right - left) / 2;
            
            res = guess(mid);
            if(res == 1){
                left = mid + 1;
            }else if(res == -1){
                right = mid - 1;
            }else if(res == 0){
                return mid;
            }
        }
        
        return n+1;
    }
};