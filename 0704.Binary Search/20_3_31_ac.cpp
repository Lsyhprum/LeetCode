# include <iostream>
# include <vector>

using namespace std;

//Runtime 58.37%
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.size() == 0) return -1;

        int left = 0, right = nums.size() - 1;
        int mid, mid_val;
        while(left <= right){
            mid = left + (right - left) / 2;
            mid_val = nums[mid];

            if(mid_val > target){
                right = mid - 1;
            }else if(mid_val < target){
                left = mid + 1;
            }else{
                return mid;
            }
        }
        return -1;
    }
};

int main(){
    Solution sol;
    vector<int> v = {};
    cout << sol.search(v, 1) << endl;
    return 0;
}