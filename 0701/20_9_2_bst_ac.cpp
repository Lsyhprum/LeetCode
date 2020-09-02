#include <iostream>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == nullptr){
            root = new TreeNode(val);
            return root;
        }
            

        if(root->val <= val){
            if(root->right != nullptr){
                insertIntoBST(root->right, val);
            } else {
                TreeNode *node = new TreeNode(val);
                root->right = node;
            }
        }else{
            if(root->left != nullptr){
                insertIntoBST(root->left, val);
            }else{
                TreeNode *node = new TreeNode(val);
                root->left = node;
            }
        }

        return root;

    }
};