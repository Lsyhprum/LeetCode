# include <iostream>
# include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0, right = numbers.size()-1, val;
        vector<int> ans;

        while(left < right){
            val = numbers[left] + numbers[right];
            if(val < target){
                left ++;
            }else if(val > target){
                right --;
            }else{
                ans.push_back(left + 1);
                ans.push_back(right + 1);
                return ans;
            }
        }

        return ans;
    }
};

int main(){

    Solution sol;

    vector<int> val = {2, 7, 11, 15};
    vector<int> ans = sol.twoSum(val, 9);
    cout << ans[0] << " " << ans[1] << endl;
    return 0;
}