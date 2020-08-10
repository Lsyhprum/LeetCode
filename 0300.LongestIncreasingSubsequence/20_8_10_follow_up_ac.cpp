#include <iostream>
#include <vector>

using namespace std;

//time complexity : O(NlogN), 96.19%
//memory complexity : O(N), 9.93%
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        // 使用 dp 的时间复杂度为 O(N^2), 其主要的时间浪费在查找之前的最长 LIS
        // follow up 中给出的时间复杂度为 O(NlogN), 因此可能使用的算法为二分法
        // 当前问题转化为如何使用二分法查找 N-1 的数组中， nums[j] < nums[i], 且 dp[j] 最大的问题
        // 问题1 ： 二分查找前提为 有序的连续数组，如何进行排序 ---> O(NlogN)
        // 方法废弃

        // 贪心 + 二分
        // 使用贪心构成有序的数组, 其基于一个前提：同等长度下，末尾数越小的子序列更有可能构成 LIS
        // 明确状态：tail[i] 长度为 i 时，最小的子序列末尾数
        
        int len = nums.size();
        if(len < 2) return len;

        vector<int> tail;
        tail.emplace_back(nums[0]);

        int end = 0;

        for(int i = 1; i < len; i ++){
            if(tail[end] < nums[i]){
                tail.emplace_back(nums[i]);
                end ++;
            }else{
                // 左闭右开 寻找最右
                int left = 0;
                int right = end;
                while(left < right){
                    int mid = (right - left) / 2 + left;
                    if(tail[mid] < nums[i]){
                        left = mid + 1;
                    }else{
                        right = mid;
                    }
                }

                tail[left] = nums[i];
            }
        }

        return end + 1;
    }
};

int main(){
    Solution sol;
    vector<int> nums = {10,9,2,5,3,7,101,18};
    cout << sol.lengthOfLIS(nums);

    return 0;
}