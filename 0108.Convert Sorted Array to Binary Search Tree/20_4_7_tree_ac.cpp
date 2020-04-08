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
        TreeNode *root = NULL;

        int left = 0, right = nums.size() - 1;

        recursion(nums, &root, left, right);

        return root;
    }

private:
    void recursion(vector<int> &nums, TreeNode **root, int left, int right){
        if(left <= right){
            int mid = left + (right - left) / 2;

            (*root) = new TreeNode(nums[mid]);

            recursion(nums, &((*root)->left), left, mid - 1);
            recursion(nums, &((*root)->right), mid + 1, right);
        }
    }
};

int main(){

    Solution sol;

    vector<int> v = {-10, -3, 0, 5, 9};
    TreeNode *root = sol.sortedArrayToBST(v);

    inorder(root);
    
    return 0;
}