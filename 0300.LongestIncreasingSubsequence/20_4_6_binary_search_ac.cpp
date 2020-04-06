# include <iostream>
# include <vector>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> top(nums.size());
        int piles = 0;

        for(int i = 0; i < nums.size(); i ++){
            int poker = nums[i];

            int left = 0, right = piles - 1;

            while(left <= right){
                int mid = left + (right - left) / 2;

                if(top[mid] < poker){
                    left = mid + 1;
                }else{
                    right = mid - 1;
                }
            }
            
            if(left == piles) piles ++;
            top[left] = poker;
        }

        return piles;
    }
};

int main(){
    Solution sol;
    vector<int> v = {1, 2, 3 ,4 ,5 ,6 ,7 };
    cout << sol.lengthOfLIS(v);
    return 0;
}