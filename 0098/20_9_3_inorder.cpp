#include <iostream>
#include <vector>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left_, TreeNode *right_) : val(x), left(left_), right(right_) {}
};

// Time complexity : O(N)
// Memory complexity : O(N)
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if(root == nullptr) return true;

        TreeNode *pre = nullptr;
        return InOrder(root, pre);
    }

private:
    bool InOrder(TreeNode* root, TreeNode*& pre){
        if(root == nullptr) return true;

        bool res = InOrder(root->left, pre);

        if(pre == nullptr) 
            pre = root;
        else 
            if(pre->val >= root->val) return false;
            else pre = root;

        bool res2 = InOrder(root->right, pre);

        return res && res2;
    }
};
int main(){
    Solution sol;

    // TreeNode *root6 = new TreeNode(6);
    // TreeNode *root4 = new TreeNode(3);
    // TreeNode* root3 = new TreeNode(4);
    // TreeNode* root2 = new TreeNode(1);
    //TreeNode* root = new TreeNode();

    cout << sol.isValidBST(nullptr);

    return 0;
}