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
    int countNodes(TreeNode* root) {
        int num = 0;

        recursion(root, num);

        return num;
    }

    void recursion(TreeNode* root, int &num) {
        if(root == nullptr) return;

        recursion(root->left, num);
        num += 1;
        recursion(root->right, num);
    }
};

int main() {
    Solution sol;
    TreeNode *node5 = new TreeNode(6);
    TreeNode *node3 = new TreeNode(4);
    TreeNode *node4 = new TreeNode(5);
    TreeNode *node2 = new TreeNode(3);
    node2->left = node5;
    TreeNode *node1 = new TreeNode(2);
    node1->left = node3;
    node1->right = node4;
    TreeNode *root = new TreeNode(1);
    // root->left = node1;
    // root->right = node2;
    std::cout << sol.countNodes(root);
    return 0;
}