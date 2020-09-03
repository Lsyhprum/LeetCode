#include <iostream>
#include <algorithm>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// time complexity : 92.76%
class Solution {
public:
    int getMinimumDifference(TreeNode* root) {
        
        InOrder(root);

        return diff;
    }

private:
    int diff = INT_MAX;
    int pre = -1;

    void InOrder(TreeNode* node){
        if(node == nullptr) return ;

        InOrder(node->left);

        if(pre != -1){
            diff = min(diff, abs(node->val - pre));
        }

        pre = node->val;
            
        InOrder(node->right);
    }
};