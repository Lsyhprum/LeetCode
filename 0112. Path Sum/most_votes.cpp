# include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool hasPathSum(TreeNode *root, int sum) {
        if (root == NULL) return false;
        if (root->val == sum && root->left ==  NULL && root->right == NULL) return true;
        return hasPathSum(root->left, sum-root->val) || hasPathSum(root->right, sum-root->val);
    }
};

int main(){
    Solution sol;

    TreeNode *root = new TreeNode(5);
    TreeNode *n1 = new TreeNode(4);
    TreeNode *n2 = new TreeNode(8);
    TreeNode *n3 = new TreeNode(11);
    TreeNode *n4 = new TreeNode(13);
    TreeNode *n5 = new TreeNode(4);
    TreeNode *n6 = new TreeNode(7);
    TreeNode *n7 = new TreeNode(2);
    TreeNode *n8 = new TreeNode(1);

    root->left = n1;
    root->right = n2;
    n1->left = n3;
    n2->left = n4;
    n2->right = n5;
    n3->left = n6;
    n3->right = n7;
    n5->right = n8;

    cout << sol.hasPathSum(root, 22);
    return 0;
}