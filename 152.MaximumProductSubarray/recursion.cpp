# include <iostream>
# include <algorithm>
# include <vector>

using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int MAX[nums.size()];
        int MIN[nums.size()];

        MAX[0] = nums[0];
        MIN[0] = nums[0];

        for(int i = 1; i < nums.size(); i ++){
            if(nums[i] > 0){
                MAX[i] = max(MAX[i-1] * nums[i], nums[i]);
                MIN[i] = min(MIN[i-1] * nums[i], nums[i]);
            }else{       
                MAX[i] = max(MIN[i-1]*nums[i], nums[i]);
                MIN[i] = min(MAX[i-1]*nums[i], nums[i]);
            }
        }

        int ans = MAX[0];
        for(int i = 1; i < nums.size(); i ++){
            if(ans < MAX[i])
                ans = MAX[i];
        }
        return ans;
    }
};

int main(){
    vector<int> v = {-2};
    cout << Solution().maxProduct(v) << "\n";
    return 0;
}