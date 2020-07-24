# include <iostream>
# include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/**
 * 1. 明确变量：full binary tree 的数量
 * 2. 明确 dp 数组含义： dp[i] 当存在 i 个结点时的 full binary tree 数量
 * 3. 明确选择： dp[i] = dp[i - 2] + dp[i - 4] * dp[i - 4] + dp[i - 6]
 * 4. 明确 base case: dp[1] = 1
 * 
 **/
class Solution {
public:
    vector<TreeNode*> allPossibleFBT(int N) {
        vector<int> dp(N);
        
    }
};

int main(){
    Solution sol = Solution();
    vector<TreeNode*> res = sol.allPossibleFBT(7);
    cout << res << endl;
    return 0;
}