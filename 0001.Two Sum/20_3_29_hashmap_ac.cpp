# include <iostream>
# include <unordered_map>
# include <vector>

using namespace std;

// Runtime: 64.10%
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        unordered_map<int, int> mp;
        unordered_map<int, int>::iterator it;

        for(int i = 0; i < nums.size(); i ++){
            it = mp.find(target - nums[i]);
            if(it != mp.end()){
                return vector<int>({it->second, i});
            }else{
                mp[nums[i]] = i;
            }
        }

        return res;
    }
};

int main(){
    Solution sol;
    vector<int> v = {3, 3};
    vector<int> res = sol.twoSum(v, 6);
    cout << res[0] << " " << res[1] << endl;

    return 0;
}