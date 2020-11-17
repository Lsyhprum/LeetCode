#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Time complexity : O(N), Runtime : 46.80%
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root == nullptr) return true;
        return recursion(root->left, root->right);
    }

    bool recursion(TreeNode* left, TreeNode* right) {
        if(left == nullptr && right == nullptr) return true;
        if(left == nullptr || right == nullptr) return false;

        if(left->val == right->val) {
            return recursion(left->left, right->right) && 
                    recursion(left->right, right->left);
        }else{
            return false;
        }
    }
};

int main() {
    Solution sol;

    TreeNode* root = new TreeNode(1);
    root -> left = new TreeNode(2);
    root -> right = new TreeNode(2);
    
    root -> left -> left = new TreeNode(3);
    root -> left -> right = new TreeNode(4);

    root -> right -> left = new TreeNode(4);
    root -> right -> right = new TreeNode(3);

    std::cout << sol.isSymmetric(root);
    return 0;
}