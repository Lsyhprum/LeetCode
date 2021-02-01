#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if(nums.size() < 2) return 0;

        int max_val = *max_element(nums.begin(), nums.end());
        int min_val = *min_element(nums.begin(), nums.end());

        int d = max(1, (int)((max_val - min_val) / (nums.size() - 1)));
        int bucketsize = (max_val - min_val) / d + 1;

        vector<pair<int, int>> bucket(bucketsize, {-1, -1});

        for(int i = 0; i < nums.size(); i ++) {
            int idx = (nums[i] - min_val) % d;

            if(bucket[idx].first == -1) {
                bucket[idx].first = bucket[idx].second = nums[i];
            } else {
                bucket[idx].first = min(bucket[idx].first, nums[i]);
                bucket[idx].second = max(bucket[idx].second, nums[i]);
            }
        }

        int res = 0;
        int pre = -1;
        for(int i = 0; i < bucketsize; i ++) {
            if(bucket[i].first == -1) continue;

            if(pre != -1) {
                res = max(res, bucket[i].first - bucket[pre].second);
            }
            pre = i;
        }

        return res;
    }
};