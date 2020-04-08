#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int maxDepth(TreeNode* root) {
        return recursion(root);
    }

    int recursion(TreeNode* root){
        if(root == nullptr)
            return 0;

        int left = recursion(root->left);
        int right = recursion(root->right);

        return left > right ? left + 1 : right + 1;
    }
};