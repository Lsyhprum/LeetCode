#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res = {-1, -1};

        if(nums.size() == 0) return res;

        int low = 0, high = nums.size();

        while(low < high) {
            //std::cout << low << " " << high << std::endl;
            int mid = (low + high) / 2;
            //std::cout << "mid : " << mid << std::endl;
           // std::cout << nums[mid] << std::endl;
            if(nums[mid] >= target) {
                high = mid;
            } else {
                low = mid + 1;
            }
            //std::cout << "wtf" << std::endl;
        }
        //std::cout << "wtf " << low << std::endl;
        //std::cout << nums[low] << std::endl;

        if(low >= nums.size() || nums[low] != target) {
            return res;
        }
        res[0] = low;

        low = 0, high = nums.size();

        while(low < high) {
            int mid = (low + high) / 2;
            std::cout << "mid : " << mid << std::endl;
            
            if(nums[mid] <= target) {
                low = mid + 1;
            }else{
                high = mid;
            }
        }
        if(low-1 < 0) return vector<int>{-1, -1};
        res[1] = low - 1;
        std::cout << nums[low-1] << std::endl;
        

        return res;
    }
};

int main() {
    Solution sol;
    vector<int> v1 = {2, 2};
    vector<int> v = sol.searchRange(v1, 2);

    std::cout << v[0] << " " << v[1] << std::endl;
    return 0;
}