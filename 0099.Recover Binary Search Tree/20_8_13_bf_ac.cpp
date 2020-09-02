#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
 
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    void recoverTree(TreeNode* root) {
        vector<int> nums;

        InOrder(root, nums);

        sort(nums.rbegin(), nums.rend());

        for(int i = 0; i < nums.size(); i ++)
            cout << nums[i] << endl;

        cout << "----" << endl;

        InOrder2(root, nums);
    }

private:
    void InOrder(TreeNode* root, vector<int> &nums){
        if(root == nullptr) return;

        InOrder(root->left, nums);

        nums.push_back(root->val);

        InOrder(root->right, nums);
    }

    void InOrder2(TreeNode* root, vector<int> &nums) {
        if(root == nullptr) return;

        InOrder2(root->left, nums);

        cout << root->val << " " << nums.back() << endl;
        root->val = nums.back();
        nums.pop_back();

        InOrder2(root->right, nums);
    }
};

void inorder(TreeNode *node){
    if(node == nullptr) return ;

    inorder(node->left);
    cout << node->val << endl;
    inorder(node->right);
}

int main(){
    Solution sol;
    
    TreeNode* node3 = new TreeNode(2);
    TreeNode* node2 = new TreeNode(4, node3, nullptr);
    TreeNode* node1 = new TreeNode(1, nullptr, nullptr);
    TreeNode* root = new TreeNode(3, node1, node2);

    sol.recoverTree(root);

    inorder(root);

    return 0;
}