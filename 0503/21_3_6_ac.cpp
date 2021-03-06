#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> res(nums.size(), -1);

        if(nums.size() == 0) return res;

        stack<int> st;
        for(int i = 0; i < nums.size() * 2; i ++) {
            while(!st.empty() && nums[st.top() % nums.size()] < nums[i % nums.size()]) {
                //std::cout << st.top() << " " << i % nums.size() << std::endl;
                if(st.top() < nums.size()) {
                    res[st.top()] = nums[i % nums.size()];
                }
                st.pop();
            }
            st.push(i);
        }

        return res;
    }
};

int main() {
    vector<int> nums = {1, 2};
    Solution sol;
    vector<int> res = sol.nextGreaterElements(nums);
    for(int i : res) {
        std::cout << i << std::endl;
    }
    return 0;
}