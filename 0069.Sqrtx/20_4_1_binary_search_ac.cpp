# include <iostream>

using namespace std;

//Runtime 67.52%
class Solution {
public:
    int mySqrt(int x) {
        int left = 1, right = x, mid;     // left 取 0 错误
        long long val;

        while(left <= right){
            mid = left + (right - left) / 2;

            if(mid == x / mid){
                return mid;
            }else if(mid < x / mid){
                left = mid + 1;
            }else if(mid > x / mid){
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