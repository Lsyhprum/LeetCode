#include <iostream>
#include <vector>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        //cout << nums.size() << endl;
        if(nums.size() == 0) return nullptr;

        int mid = nums.size() / 2;
        TreeNode *node = new TreeNode(nums[mid]);

        vector<int> nums1(nums.begin(), nums.begin() + mid);
        vector<int> nums2(nums.begin() + mid + 1, nums.end());

        TreeNode *left = sortedArrayToBST(nums1);

        TreeNode *right = sortedArrayToBST(nums2);

        node->left = left;
        node->right = right;

        return node;
    }
};


void InOrder(TreeNode *node){
    if(node == nullptr) return ;

    InOrder(node->left);

    cout << node->val << endl;

    InOrder(node->right);
}

int main(){
    Solution sol;

    vector<int> nums = {-10, -2, 0, 5, 9};

    TreeNode*node = sol.sortedArrayToBST(nums);

    InOrder(node);
    return 0;
}