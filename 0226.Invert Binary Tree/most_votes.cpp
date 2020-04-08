# include <iostream>

using namespace std;

// Runtime 50.86% 
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void inorder(TreeNode *root){
    if(root == NULL) return;

    inorder(root->left);
    cout << root->val << endl;
    inorder(root->right);
}

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root){
            invertTree(root->left);
            invertTree(root->right);
            swap(root->left, root->right);
        }
        return root;
    }
};

int main(){
    TreeNode *root = new TreeNode(4);
    TreeNode *n1 = new TreeNode(7);
    TreeNode *n2 = new TreeNode(2);
    TreeNode *n3 = new TreeNode(9);
    TreeNode *n4 = new TreeNode(6);
    TreeNode *n5 = new TreeNode(3);
    TreeNode *n6 = new TreeNode(1);

    root->left = n1;
    root->right = n2;
    n1->left = n3;
    n1->right = n4;
    n2->left = n5;
    n2->right = n6;

    Solution sol;
    TreeNode *res = sol.invertTree(root);
    inorder(res);

    return 0;
}