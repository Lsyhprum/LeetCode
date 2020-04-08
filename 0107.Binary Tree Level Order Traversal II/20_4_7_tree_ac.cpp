# include <iostream>
# include <algorithm>
# include <vector>
# include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;

        recursion(root, ans, 1);

        reverse(ans.begin(), ans.end());

        return ans;
    }

private:
    void recursion(TreeNode* root, vector<vector<int>> &ans, int level){
        if(root){
            if(ans.size() < level){
                vector<int> v;
                ans.emplace_back(v);
            }
            ans[level - 1].emplace_back(root->val);

            recursion(root->left, ans, level + 1);
            recursion(root->right, ans, level + 1);
        }
    }
};

int main(){
    TreeNode *root = new TreeNode(4);
    TreeNode *n1 = new TreeNode(9);
    TreeNode *n2 = new TreeNode(20);
    // TreeNode *n3 = new TreeNode(9);
    // TreeNode *n4 = new TreeNode(6);
    TreeNode *n5 = new TreeNode(15);
    TreeNode *n6 = new TreeNode(7);

    root->left = n1;
    root->right = n2;
    // n1->left = n3;
    // n1->right = n4;
    n2->left = n5;
    n2->right = n6;

    Solution sol;

    vector<vector<int>> ans = sol.levelOrderBottom(root);

    for(int i = 0; i < ans.size(); i ++){
        for(int j = 0; j < ans[i].size(); j ++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}