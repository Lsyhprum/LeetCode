#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// 1000
// 500
// 250
// 125
// 
class Solution {
public:
    int minSteps(int n) {
        vector<int> dp(n + 1, INT_MAX);
        dp[1] = 0;

        for(int i = 2; i <= n; i ++){
            if(i % 2 == 0){
                dp[i] = dp[i / 2] + 2;
            }else{
                dp[i] = min(dp[i], i);
                int j = i;
                for(int j = i + i; j <= n; j += i){
                    if(j == i + i) dp[j] = dp[i] + 2;
                    else dp[j] = dp[j - i] + 1;
                }
            }
        }

        return dp[n];
    }
};

int main(){

    return 0;
}