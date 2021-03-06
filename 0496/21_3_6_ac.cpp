#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;

// time complexity : O(N + M)
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {

        unordered_map<int, int> map;
        stack<int> st;

        for(int val : nums2) {
            map[val] = -1;
            while(!st.empty() && st.top() < val) {
                int v = st.top();
                map[st.top()] = val;
                st.pop();
            }
            st.push(val);
        }

        vector<int> res(nums1.size());
        for(int i = 0; i < nums1.size(); i ++) {
            res[i] = map[nums1[i]];
        }
        
        return res;
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = {1, 3, 5, 2, 4};
    vector<int> nums2 = {6, 5, 4, 3, 2, 1, 7};
    vector<int> res = sol.nextGreaterElement(nums1, nums2);

    for(int val : res) {
        std::cout << val << std::endl;
    }
    
    return 0;
}