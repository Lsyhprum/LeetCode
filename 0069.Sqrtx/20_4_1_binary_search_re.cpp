# include <iostream>

using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        int left = 0, right = x, mid, val;

        while(left <= right){
            mid = left + (right - left) / 2;
            val = mid * mid;

            if(val == x){
                return mid;
            }else if(val < x){
                left = mid + 1;
            }else if(val > x){
                right = mid - 1;
            }
        }

        return right;
    }
};

int main(){
    Solution sol;
    cout << sol.mySqrt(INT_MAX - 1) << endl;
    return 0;
}