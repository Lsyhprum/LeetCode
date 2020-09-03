#include <iostream>
#include <vector>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Time complexity : 90.27%
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        //cout << nums.size() << endl;
        if(nums.size() == 0) return nullptr;
        
        TreeNode *node = Recursion(nums, 0, nums.size() - 1);

        return node;
    }

    TreeNode* Recursion(const vector<int>& nums, int l, int r){
        if(l > r) return nullptr;
        //cout << l << " " << r << endl;

        int mid = (l + r)/2;
        TreeNode *node = new TreeNode(nums[mid]);

        node->left = Recursion(nums, l, mid-1);
        node->right = Recursion(nums, mid + 1, r);

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