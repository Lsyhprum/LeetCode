# include <iostream>
# include <vector>

using namespace std;

// Runtime 96.24%
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left = 0, right = nums.size() - 1, mid;
        while(left < right){
            mid = left + (right - left) / 2;
            if(nums[mid] < nums[mid + 1]){
                left = mid + 1;
            }else{
                right = mid;
            }
        }

        return left;
    }
};

int main(){
    Solution sol;
    vector<int> v = {1};
    cout << sol.findPeakElement(v) << endl;
    return 0;
}