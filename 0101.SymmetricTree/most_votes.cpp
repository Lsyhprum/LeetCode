# include <iostream>
# include <stack>

using namespace std;

// Runtime 36.47%
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root == NULL) return true;
        return isMirror(root->left, root->right);
    }

private:
    bool isMirror(TreeNode* t1, TreeNode* t2){
        if(t1 == NULL && t2 == NULL) return true;
        if(t1 == NULL || t2 == NULL || t1->val != t2->val) return false;

        return isMirror(t1->left, t2->right) && isMirror(t1->right, t2->left);
    }
};

int main(){
    TreeNode* root = new TreeNode(1);
    root -> left = new TreeNode(2);
    root -> right = new TreeNode(2);
    
    root -> left -> left = new TreeNode(3);
    //root -> left -> right = new TreeNode(4);

    root -> right -> left = new TreeNode(4);
    root -> right -> right = new TreeNode(3);

    Solution sol;
    cout << sol.isSymmetric(root) << endl;
    return 0;
}