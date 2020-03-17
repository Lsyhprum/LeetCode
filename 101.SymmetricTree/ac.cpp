# include <iostream>
# include <stack>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
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

        stack<TreeNode*> sleft;
        stack<TreeNode*> sright;

        TreeNode* left = root -> left;
        TreeNode* right = root -> right;

        sleft.push(left);
        sright.push(right);

        bool flag = true;

        while(!sleft.empty() && !sright.empty()){
            left = sleft.top();
            right = sright.top();
            sleft.pop();
            sright.pop();

            if(!left && !right)
                continue;
            
            if(left && right && left -> val == right -> val){
                sleft.push(left -> right);
                sleft.push(left -> left);
                sright.push(right -> left);
                sright.push(right -> right);
            }else{
                flag = false;
                break;
            }
        }

        if(!sleft.empty()) flag = false;
        if(!sright.empty()) flag = false;

        return flag;
    }
};

int main(){
    TreeNode* root = new TreeNode(1);
    root -> left = new TreeNode(2);
    root -> right = new TreeNode(2);
    
    root -> left -> left = new TreeNode(3);
    //root -> left -> right = new TreeNode(4);

    root -> right -> left = new TreeNode(3);
    root -> right -> right = new TreeNode(3);

    Solution sol;
    cout << sol.isSymmetric(root) << endl;
    return 0;
}