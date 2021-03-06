#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;

// time complexity : O(N + M)
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res(nums1.size(), -1);

        unordered_map<int, int> nums2index;

        for(int i = 0; i < nums1.size(); i ++) {
            nums2index[nums1[i]] = i;
        }

        stack<int> st;
        for(int val : nums2) {
            while(!st.empty() && st.top() < val) {
                if(nums2index.count(st.top())) {
                    res[nums2index[st.top()]] = val;
                    //std::cout << res[nums2index[st.top()]] << " " << val << std::endl;
                }
                st.pop();
            }
            st.push(val);
        }
        
        return res;
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = {1, 3, 5, 2, 4};
    vector<int> nums2 = {6, 5, 4, 3, 2, 1, 7};
    // vector<int> nums1 = {1, 2, 3, 4};
    // vector<int> nums2 = {1, 2, 3, 4, 5};
    vector<int> res = sol.nextGreaterElement(nums1, nums2);

    for(int val : res) {
        std::cout << val << std::endl;
    }
    
    return 0;
}