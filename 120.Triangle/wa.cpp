# include <iostream>
# include <algorithm>
# include <vector>

using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int h = triangle.size();
        
        if(h == 0) return 0;

        int dp[h + 1][h + 1];
        for(int i = 0; i <= h; i ++){
            for(int j = 0; j <= h; j ++){
                dp[i][j] = 0;                        // 反思：谨慎使用 0 作为最小值
            }
        }
        dp[1][1] = triangle[0][0];

        for(int i = 2;i <= h;i ++){
            for(int j = 1;j <= i; j ++){
                if(dp[i-1][j-1] == 0)
                    dp[i][j] = dp[i-1][j] + triangle[i-1][j-1];
                else if(dp[i-1][j] == 0)
                    dp[i][j] = dp[i-1][j-1] + triangle[i-1][j-1];
                else
                    dp[i][j] = min(dp[i-1][j-1], dp[i-1][j]) + triangle[i-1][j-1];
            }
        }

        for(int i = 1; i <=h; i ++){
            for(int j = 1; j <= i; j ++){
                cout << dp[i][j] << " ";
            }
            cout << "\n";
        }

        int ans = dp[h][1];
        for(int i = 2; i <= h; i ++){
            if(dp[h][i] < ans)
                ans = dp[h][i];
        }

        return ans;
    }
};

int main(){
    vector<int> v1 = {7};
    vector<int> v2 = {-5, 9};
    vector<int> v3 = {6, 5, 2};
    vector<int> v4 = {-8, -2, -7, 3};
    vector<int> v5 = {-2, 6, -6, -1, 4};
    vector<vector<int>> v = {v1, v2, v3, v4, v5};

    cout << Solution().minimumTotal(v);
    return 0;
}