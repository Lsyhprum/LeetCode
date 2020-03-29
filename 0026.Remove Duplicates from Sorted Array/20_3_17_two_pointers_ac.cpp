# include <iostream>
# include <vector>

using namespace std;

//Runtime: 89.91%
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len = nums.size();

        if(len == 0 || len == 1) return len;

        int fast = 0, slow = 0;

        while(fast < len){
            while(nums[slow] == nums[fast]) fast++;
            nums[++slow] = nums[fast];
        }

        return slow;
    }
};

int main(){
    Solution sol;

    vector<int> v = {1, 1, 2};

    int ans = sol.removeDuplicates(v);
    cout << ans << endl;

    for(int i = 0; i < ans; i ++){
        cout << v[i] << endl;
    }

    return 0;
}