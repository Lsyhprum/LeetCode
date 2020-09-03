#include <iostream>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Time complexity : 95.41%
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root == nullptr || root->val == val) return root;

        if(val < root->val)
            return searchBST(root->left, val);
        else
            return searchBST(root->right, val);
    }
};