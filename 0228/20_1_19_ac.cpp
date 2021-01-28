#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;

        int len = nums.size();
        if(len == 0) return res;

        for(int i = 0; i < nums.size(); i ++) {
            int start = i;
            int end = i + 1;
            while(end < nums.size() && nums[end] == nums[end - 1] + 1) 
                end ++;

            string tmp = to_string(nums[start]);
            if(start != end - 1) {
                tmp.append("->");
                tmp.append(to_string(nums[end - 1]));
            }
    
            res.push_back(tmp);

            i = end - 1;
        }

        return res;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {0};
    vector<string> res = sol.summaryRanges(nums);
    for(string s : res) {
        std::cout << s << std::endl;
    }

    return 0;
}