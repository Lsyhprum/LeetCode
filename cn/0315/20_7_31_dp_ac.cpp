#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int nums_size = nums.size();
        vector<int> res(nums.size(), 0);
        int dp[nums_size][nums_size] = {0};
        dp[nums_size - 1][nums_size - 1] = 0;

        for(int i = nums_size - 2; i >= 0; i --){
            for(int j = i + 1; j < )
        }
    }
};

int main(){

    return 0;
}