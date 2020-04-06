# include <iostream>

using namespace std;

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    bool isBadVersion(int version);

    int firstBadVersion(int n) {
        int left = 1, right = n, mid;

        while(left <= right){
            mid = left + (right - left) / 2;

            if(isBadVersion(mid)){
                right = mid - 1;
            }else{
                left = mid + 1;
            }
        }
        return left;
    }
};

// g g g g b b b
int main(){

    return 0;
}