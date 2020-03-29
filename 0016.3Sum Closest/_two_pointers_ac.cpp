# include <iostream>
# include <algorithm>
# include <vector>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int res = nums[0] + nums[1] + nums[2];
        sort(nums.begin(), nums.end());

        int diff = abs(res - target);

        for(int i = 0;i <= nums.size() - 3;i ++){
            int left = i + 1, right = nums.size() - 1;
            while(left < right){
                int sum = nums[i] + nums[left] + nums[right];
                int d = abs(sum - target);
                if(diff > d){
                    diff = d;
                    res = sum;
                }

                if(sum < target) left ++;
                else right --;
            }
        }
        return res;
    }
};

int main(){
    return 0;
}