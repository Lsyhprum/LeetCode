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
        InOrder(root);
        return res;
    }

private:
    int num = 0;
    int res = 0;

    void InOrder(TreeNode* node){
        if(node){
            InOrder(node->left);
            num -- ;
            if(num == 0) {
                res = node->val;
                return;
            }
            InOrder(node->right);
        }
    }
};