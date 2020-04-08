# include <iostream>
# include <vector>

using namespace std;

// Runtime 13.58%
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void InOrder(TreeNode *root){
    if(root == NULL) return;

    InOrder(root->left);
    cout << root->val << endl;
    InOrder(root->right);
}

class Solution {
public:
    TreeNode* buildTree(vector<int> preorder,vector<int> inorder) {
        if(inorder.size() == 0) return NULL;
        if(inorder.size() == 1) return new TreeNode(inorder[0]);

        // for(int i = 0; i < preorder.size(); i ++){
        //     cout << preorder[i] << " ";
        // }
        // cout << endl;

        // for(int i = 0; i < inorder.size(); i ++){
        //     cout << inorder[i] << " ";
        // }
        // cout << endl;

        TreeNode *root = new TreeNode(preorder[0]);
        // 不含重复数字
        int pos = 0;
        while(pos < inorder.size() && inorder[pos] != preorder[0]){ pos ++; }

        vector<int> left_preorder(preorder.begin() + 1, preorder.begin() + pos + 1);
        vector<int> right_preorder(preorder.begin() + pos + 1, preorder.end());

        vector<int> left_inorder(inorder.begin(), inorder.begin() + pos);
        vector<int> right_inorder(inorder.begin() + pos + 1, inorder.end());

        root->left = buildTree(left_preorder, left_inorder);
        root->right = buildTree(right_preorder, right_inorder);

        return root;
    }
};

int main(){
    Solution sol;

    vector<int> preorder = {1, 2, 4, 7, 3, 5, 6, 8};
    vector<int> inorder = {4, 7, 2, 1, 5, 3, 8, 6};
    TreeNode* root = sol.buildTree(preorder, inorder);

    InOrder(root);

    return 0;
}