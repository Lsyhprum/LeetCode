# include <iostream>
# include <algorithm>
# include <vector>
# include <queue>

using namespace std;

// Runtime 23.73%
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void inorder(TreeNode *root){
    if(root == NULL) return;

    inorder(root->left);
    cout << root->val << endl;
    inorder(root->right);
}

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size() == 0) return NULL;
        if(nums.size() == 1) return new TreeNode(nums[0]);

        int mid = nums.size() / 2;
        TreeNode* root = new TreeNode(nums[mid]);

        vector<int> left(nums.begin(), nums.begin() + mid);
        vector<int> right(nums.begin() + mid + 1, nums.end());
        
        root->left = sortedArrayToBST(left);
        root->right = sortedArrayToBST(right);

        return root;
    }
};

int main(){

    Solution sol;

    vector<int> v = {-10, -3, 0, 5, 9};
    TreeNode *root = sol.sortedArrayToBST(v);

    inorder(root);
    
    return 0;
}