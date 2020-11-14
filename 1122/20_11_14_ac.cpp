#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> res;
        map<int, int> mp;

        for(int i : arr1) {
            mp[i] ++;
        }

        for(int i : arr2) {
            for(int j = 0; j < mp[i]; j ++) {
                res.push_back(i);
            }

            mp[i] = 0;
        }

        for(auto i : mp) {
            for(int j = 0; j < i.second; j ++)
                res.push_back(i.first);
        }

        return res;
    }
};

int main() {

    Solution sol;
    vector<int> v1 = {222222222};
    vector<int> v2 = {};
    vector<int> v = sol.relativeSortArray(v1, v2);

    for(int i : v) {
        std::cout << i << " ";
    }
    
    return 0;
}