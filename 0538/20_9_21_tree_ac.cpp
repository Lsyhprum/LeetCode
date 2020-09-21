#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x, TreeNode*left1, TreeNode *right1) : val(x), left(left1), right(right1) {}
};

class Solution {
public:
    TreeNode* convertBST(TreeNode* root) {
        int sum = 0;
        TreeNode *tmp = root;

        fun1(tmp, sum);

        fun2(tmp, sum);

        return root; 
    }

    void fun1(TreeNode *root, int &sum) {
        if(root == nullptr) return;

        fun1(root->left, sum);

        sum += root->val;

        fun1(root->right, sum);
    }

    void fun2(TreeNode *root, int &sum) {
        if(root == nullptr) return ;

        fun2(root->left, sum);

        sum -= root->val;
        root->val += sum;

        fun2(root->right, sum);
    }

};

int main() {
    Solution sol;

    TreeNode *left = new TreeNode(2, nullptr, nullptr);
    TreeNode *right = new TreeNode(13, nullptr, nullptr);
    TreeNode *root = new TreeNode(5, left, right);
   

    sol.convertBST(root);
    return 0;
}