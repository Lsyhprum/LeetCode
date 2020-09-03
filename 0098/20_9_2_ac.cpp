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
// Memory complexity : O(2N)
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if(root == nullptr) return true;

        vector<int> val;
        InOrder(root, val);

        int pre = val[0];
        for(int i = 1; i < val.size(); i ++){
            if(val[i] <= pre) return false;

            pre = val[i];
        }

        return true;
    }

private:
    void InOrder(TreeNode* root, vector<int> &val){
        if(root == nullptr) return;

        InOrder(root->left, val);

        val.push_back(root->val);

        InOrder(root->right, val);
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