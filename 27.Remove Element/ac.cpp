# include <iostream>
# include <vector>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int left = 0;
        int right = nums.size() - 1;
        int ans = nums.size();

        while(left < right){
            if(nums[left] == val && nums[right] != val){
                nums[left] = nums[right];
                right --;
                left ++;
                ans --;
            }

            while(left < right && nums[left] != val){
                left ++;
            } 
            while(left < right && nums[right] == val){
                right --;
                ans --;
            } 
        }
        if(left == right && nums[left] == val)
            ans --;

        return ans;
    }
};

int main(){
    Solution sol;
    vector<int> v = {1, 1};
    int ans = sol.removeElement(v, 1);
    cout << ans << endl;
    for(int i = 0; i < ans; i ++){
        cout << v[i] << endl;
    }
    return 0;
}