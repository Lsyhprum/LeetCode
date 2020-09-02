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
    int kthSmallest(TreeNode* root, int k) {
        num = k;

        return InOrder(root);
    }

private:
    int num = 0;

    int InOrder(TreeNode* node){
        if(node == nullptr) return 0;

        int res = InOrder(node->left);
        if(res != 0) return res;

        num --;
        if(num == 0) return node->val;
        
        return InOrder(node->right);
    }
};