#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mp;
        vector<int> res;
        for(int i : nums1) {
            if(mp.find(i) == mp.end())
                mp[i] += 1;
        }

        for(int j : nums2) {
            if(mp.find(j) != mp.end()) {
                mp[j] += 1;
                if(mp[j] == 2) res.push_back(j);
            }
            
        }

        return res;
    }
};

int main() {

    Solution sol;

    vector<int> nums1 = {4, 9, 5, 5};
    vector<int> nums2 = {9, 4, 9, 8, 4, 6, 6};

    for(int i : sol.intersection(nums1, nums2)) {
        std::cout << i << std::endl;
    }

    return 0;
}