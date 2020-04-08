# include <iostream>
# include <algorithm>

using namespace std;

// Runtime 81.00% 
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if(root == NULL) return true;

        int left_height = max_height(root->left);
        int right_height = max_height(root->right);

        if(left_height == -1 || right_height == -1) return false;


        return abs(left_height - right_height) <= 1;
    }

private:
    int max_height(TreeNode* root){
        if(root == NULL) return 0;

        int left_height = max_height(root->left);
        int right_height = max_height(root->right);

        if(left_height == -1 || right_height == -1)
            return -1;

        if(abs(left_height - right_height) > 1){
            return -1;
        }else{
            return (left_height > right_height ? left_height : right_height) + 1;
        }
    }
};

int main(){
    Solution sol;

    TreeNode *root = new TreeNode(1);
    TreeNode *n1 = new TreeNode(2);
    TreeNode *n2 = new TreeNode(2);
    TreeNode *n3 = new TreeNode(3);
    TreeNode *n4 = new TreeNode(3);
    TreeNode *n5 = new TreeNode(4);
    TreeNode *n6 = new TreeNode(4);

    root->left = n1;
    root->right = n2;
    n1->left = n3;
    n2->right = n4;
    n3->left = n5;
    n4->right = n6;

    cout << sol.isBalanced(root);

    return 0;
}