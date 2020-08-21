#include <iostream>
#include <algorithm>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root == nullptr) return 0;

        if(root->left == nullptr && root->right == nullptr) return 1;

        if(root->left == nullptr) return minDepth(root->right) + 1;

        if(root->right == nullptr) return minDepth(root->left) + 1;

        return min(minDepth(root->left), minDepth(root->right)) + 1;

    }

};

int main(){
    Solution sol;
    
    TreeNode *node4 = new TreeNode(7);
    TreeNode *node3 = new TreeNode(15);
    TreeNode *node2 = new TreeNode(20);
    node2->left = node3;
    node2->right = node4;
    TreeNode *node1 = new TreeNode(9);
    TreeNode *node5 = new TreeNode(10);
    node1->left = node5;
    TreeNode *node = new TreeNode(3);
    node->left = node1;
    node->right = node2;
    cout << sol.minDepth(node);
    return 0;
}