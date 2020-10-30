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

        return recursion(root, 0);

    }

    int recursion(TreeNode* node, int i) {
        if(node == nullptr) return 0;

        int tmp = i * 10 + node->val;

        if(node->left == nullptr && node->right == nullptr)
            return tmp;;

        return recursion(node->left, tmp) + recursion(node->right, tmp);
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