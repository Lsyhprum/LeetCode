#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;

// Time complexity : O(n + m)
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res(nums1.size());

        stack<int> s;
        unordered_map<int, int> map;
        for(int val : nums2){
            while(!s.empty() && s.top() < val){
                map.insert(pair<int, int>(s.top(), val));
                s.pop();
            }
            s.push(val);
        }

        for(int i = 0; i < nums1.size(); i ++){
            if(map.find(nums1[i]) == map.end())
                res[i] = -1;
            else
                res[i] = map[nums1[i]];
        }
        return res;
    }
};

int main(){
    Solution sol;
    vector<int> nums1 = {2, 4};
    vector<int> nums2 = {1, 3, 4, 2};
    for(int val : sol.nextGreaterElement(nums1, nums2)){
        cout << val << endl;
    }
    return 0;
}