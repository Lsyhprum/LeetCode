# include <iostream>
# include <vector>

using namespace std;

// Runtime 8.10%
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
    TreeNode* buildTree(vector<int> inorder,vector<int> postorder) {
        // inorder:   [9], 3, [15, 20, 7]
        // postorder: [9, 15, 7, 20], 3

        if(inorder.size() == 0) return NULL;
        // if(inorder.size() == 1)
        //     cout << inorder[0] << endl;
        if(inorder.size() == 1) return new TreeNode(inorder[0]);

        // for(int i = 0; i < inorder.size(); i ++){
        //     cout << inorder[i] << " ";
        // }
        // cout << endl;

        // for(int i = 0; i < postorder.size(); i ++){
        //     cout << postorder[i] << " ";
        // }
        // cout << endl;

        TreeNode *root = new TreeNode(postorder[postorder.size() - 1]);

        int pos = 0;
        while(pos < inorder.size() && inorder[pos] != postorder[postorder.size() - 1]){ pos ++; }

        vector<int> left_postorder(postorder.begin(), postorder.begin() + pos);
        vector<int> right_postorder(postorder.begin() + pos, postorder.end() - 1);

        vector<int> left_inorder(inorder.begin(), inorder.begin() + pos);
        vector<int> right_inorder(inorder.begin() + pos + 1, inorder.end());

        root->left = buildTree(left_inorder, left_postorder);
        root->right = buildTree(right_inorder, right_postorder);

        return root;
    }
};

int main(){
    Solution sol;

    vector<int> preorder = {9,3,15,20,7};
    vector<int> inorder = {9,15,7,20,3};
    TreeNode* root = sol.buildTree(preorder, inorder);

    InOrder(root);

    return 0;
}