# include <iostream>
# include <algorithm>

using namespace std;

// Runtime 24.69%
class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();

        int dp[512][512];

        // base case
        for(int i = 1; i <= m; i ++){
            dp[i][0] = i;
        }

        for(int j = 1; j <= n; j ++){
            dp[0][j] = j;
        }
        
        // 自底向上
        for(int i = 1; i <= m; i ++){
            for(int j = 1; j <= n; j ++){
                if(word1[i - 1] == word2[j - 1]){
                    dp[i][j] = dp[i-1][j-1];
                }else{
                    dp[i][j] = min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1])) + 1;

                    // Runtime 11.59%
                    //dp[i][j] = MIN(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]) + 1;
                }
            }
        }

        return dp[m][n];
    }

private:
    int MIN(int a, int b, int c){
        int d = min(a, b);
        return min(d, c);
    }
};

int main(){
    Solution sol;
    cout << sol.minDistance("intention", "execution");
    return 0;
}