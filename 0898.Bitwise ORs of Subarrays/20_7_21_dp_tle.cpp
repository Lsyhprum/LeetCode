# include <iostream>
# include <vector>
# include <unordered_set>

using namespace std;

/**
 * 1. 明确变量：Bitwise OR 数量
 * 2. 明确数组定义：dp[i][j] = A[i] | A[i+1] | A[i+2] | ... | A[j]
 * 3. 明确选择：dp[i][j] = dp[i-1][j] | A[i]
 * 4. 明确 Base case: 
 **/
// Time complexity: O(n^2)
// Space complexity: O(n^2)
// Running time: TLE (71 / 83 test cases passed.)
class Solution1 {
public:
    int subarrayBitwiseORs(vector<int>& A) {
        int n = A.size();
        vector< vector<int>> dp(n, vector<int>(n));
        unordered_set<int> ans(begin(A), end(A));
       /* ` */

        for(int i = 0; i < n; i ++){
            dp[i][i] = A[i];
            for(int j = i + 1; j < n; j ++){
                dp[i][j] = dp[i][j - 1] | A[j];
                //cout << "i " << i << " j " << j << " dp " << dp[i][j] << endl;
                ans.insert(dp[i][j]);

                // for(int i : ans){
                //     cout << "test " << i << endl;
                    
                // }
                //cout << endl;
            }
        }

        // for(int i : ans){
        //     cout << i << endl;
        // }
        return ans.size();
    }
};

// 滚动数组降维
// Space complexity: O(n)
class Solution {
public:
    int subarrayBitwiseORs(vector<int>& A) {
        vector<int> dp(A.size());
        unordered_set<int> ans(begin(A), end(A));

        for(int i = 0; i < A.size(); i ++){
            dp[i] = A[i];
            for(int j = i + 1; j < A.size(); j ++){
                dp[j] = dp[j - 1] | A[j];
                ans.insert(dp[j]);
            }
        }

        return ans.size();
    }
};

int main(){
    Solution sol = Solution();
    vector<int> val = {1, 2, 4};
    cout << sol.subarrayBitwiseORs(val) << endl;
    return 0;
}