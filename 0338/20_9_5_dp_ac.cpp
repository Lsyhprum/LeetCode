#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> countBits(int num) {
        if(num == 0) return vector<int>{0};
        vector<int> dp(num + 1, 0);
        // 0 0
        // 1 1
        // 2 1
        // 3 2
        // 4 1
        // 5 2
        // 6 2
        // 7 3
        // 8 1
        // 9 2
        // 10 2    10010

        dp[0] = 0;  dp[1] = 1;

        int factor = 1; 
        int pre = 1;
        for(int i = 2; i <= num; i ++){
            if(i == pow(2, factor)){
                dp[i] = 1;
                factor ++;
                pre = i;
            }else{
                dp[i] = dp[pre] + dp[i - pre];
            }
        }

        return dp;
    }
};

int main(){

    return 0;
}