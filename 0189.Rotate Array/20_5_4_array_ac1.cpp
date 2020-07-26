# include <iostream>
# include <vector>
# include <algorithm>

using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();
        reverse(nums.begin(), nums.end() - k);
        reverse(nums.end() - k, nums.end());
        reverse(nums.begin(), nums.end());
    }
};

int main(){
    Solution sol;

    vector<int> v = {1, 2, 3, 4, 5, 6, 7};
    sol.rotate(v, 3);
    for(int i = 0; i < v.size(); i ++){
        cout << v[i] << endl;
    }
    return 0;
}