#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        if(n < 2) return 0;

        int max_val = *max_element(nums.begin(), nums.end());
        int min_val = *min_element(nums.begin(), nums.end());
        int d = max(1, (max_val - min_val) / (n - 1));
        int bucketSize = (max_val - min_val) / d + 1;

        vector<pair<int, int>> bucket(bucketSize, {-1, -1});

        for(int i = 0; i < nums.size(); i ++) {
            int idx = (nums[i] - min_val) / d;
            if(bucket[idx].first == -1){
                bucket[idx].first = bucket[idx].second = nums[i];
            } else {
                bucket[idx].first = min(bucket[idx].first, nums[i]);
                bucket[idx].second = max(bucket[idx].second, nums[i]);
            }
        }

        int ret = 0;
        int prev = -1;

        for(int i = 0; i < bucketSize; i ++) {
            if(bucket[i].first == -1) continue;
            if(prev != -1) {
                ret = max(ret, bucket[i].first - bucket[prev].second);
            }
            prev = i;
        }
        return ret;
    }
};

int main() {
    vector<int> v = {1, 1, 1};
    Solution sol;
    std::cout << sol.maximumGap(v) << std::endl;
    return 0;
}