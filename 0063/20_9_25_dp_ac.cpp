#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int rows = obstacleGrid.size();
        int cols = obstacleGrid[0].size();

        // 起点、终点不可达
        if(obstacleGrid[rows - 1][cols - 1] == 1 || obstacleGrid[0][0] == 1) 
            return 0;

        vector<vector<int>> dp(rows, vector<int>(cols, 0));

        for(int i = 0; i < rows; i ++) {
            for(int j = 0; j < cols; j ++) {
                if(obstacleGrid[i][j] == 1){
                    dp[i][j] = -1;
                }
            }
        }

        for(int i = 0; i < cols; i ++) {
            if(dp[0][i] == -1) break;
            dp[0][i] = 1;
        }

        for(int i = 0; i < rows; i ++) {
            if(dp[i][0] == -1) break;
            dp[i][0] = 1;
        }

        for(int i = 1; i < rows; i ++ ) {
            for(int j = 1; j < cols; j ++) {
                if(dp[i][j] == -1) continue;
                int sum = 0;
                if(dp[i][j-1] != -1)
                    sum += dp[i][j -1];
                if(dp[i-1][j] != -1)
                    sum += dp[i-1][j];

                dp[i][j] += sum ;
            }
        }

        // for(int i = 0; i < rows; i ++)
        //     for(int j = 0; j < cols; j ++)
        //         std::cout << dp[i][j] << std::endl;

        return dp[rows - 1][cols - 1];
    }
};

int main() {
    Solution sol;

    vector<vector<int>> v = {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
    std::cout << sol.uniquePathsWithObstacles(v);

    return 0;
}