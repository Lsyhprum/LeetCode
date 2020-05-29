# include <iostream>
# include <vector>

using namespace std;

// runtime 69.84%
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int val = nums[0];
        int num = 1;

        for(int i = 1; i < nums.size(); i ++){
            if(nums[i] == val) 
                num ++;
            else
                if(num == 1){
                    val = nums[i];
                }else{
                    num --;
                }
        }
        return val;
    }
};

int main(){
    vector<int> v = {8, 8, 7, 7, 7};
    Solution sol;
    cout << sol.majorityElement(v) << endl;
    return 0;
}