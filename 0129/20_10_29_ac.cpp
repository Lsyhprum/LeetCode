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
    int sumNumbers(TreeNode* root) {
        if(root == nullptr) return 0;

        int res = 0;

        recursion(root, root->val, res);

        return res;
    }

    void recursion(TreeNode* node, int tmp, int &res) {
        // std::cout << node->val << std::endl;
        // std::cout << tmp << std::endl;
        // std::cout << res << std::endl;
        // std::cout << " " << std::endl;

        if(node->left == nullptr && node->right == nullptr) {
            res += tmp;
            return;
        }

        if(node->left) {
            recursion(node->left, tmp * 10 + node->left->val, res);
        }
        if(node->right) {
            recursion(node->right, tmp * 10 + node->right->val, res);
        }
        
        
    }
};

int main() {

    Solution sol;
    
    TreeNode node4(1);
    TreeNode node2(0);
    TreeNode node1(9);
    node1.right = &node4;
    // node1.right = &node4;
    TreeNode *node = new TreeNode(4);
    node->left = &node1;
    node->right = &node2;

    std::cout << sol.sumNumbers(node) << std::endl;

    return 0;
}