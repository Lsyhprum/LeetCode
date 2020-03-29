# include <iostream>
# include <algorithm>
# include <vector>

using namespace std;

// Runtime: 93.19%
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;

        vector<int> sorted_nums(nums);        // 拷贝
        sort(sorted_nums.begin(), sorted_nums.end());

        int left = 0, right = sorted_nums.size() - 1, val;
        while(left < right){
            val = sorted_nums[left] + sorted_nums[right];
            if(val < target){
                left ++;
            }else if(val > target){
                right --;
            }else{
                int first = -1, second = -1;

                for(int i = 0; i < nums.size(); i ++){
                    if(nums[i] == sorted_nums[left] && first == -1){
                        first = i;
                    }else if(nums[i] == sorted_nums[right] && second == -1){
                        second = i;
                    }

                    if(first != -1 && second != -1){
                        res.push_back(first);
                        res.push_back(second);
                        return res;
                    }
                }
            }
        }
        return res;
    }
};

int main(){
    Solution sol;
    vector<int> v = {3, 3};
    vector<int> res = sol.twoSum(v, 6);
    cout << res[0] << " " << res[1] << endl;
    return 0;
}