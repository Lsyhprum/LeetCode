# include <iostream>
# include <stack>

using namespace std;

// Runtime 45.86%
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        if(root == NULL) return 0;

        int num = k;

        stack<TreeNode*> s;

        while(root){
            s.push(root);
            root = root->left;
        }

        TreeNode *node = NULL;
        while(!s.empty()){
            node = s.top();
            s.pop();
            k --;

            if(k == 0)
                break;
            

            TreeNode *tmp = node->right;
            while(tmp){
                s.push(tmp);
                tmp = tmp->left;
            }
        }

        return node->val;
    }
};

int main(){
    Solution sol;
    
    TreeNode *root = new TreeNode(5);
    TreeNode *n1 = new TreeNode(3);
    TreeNode *n2 = new TreeNode(6);
    TreeNode *n3 = new TreeNode(2);
    TreeNode *n4 = new TreeNode(4);
    TreeNode *n5 = new TreeNode(1);
    //TreeNode *n6 = new TreeNode(1);

    root->left = n1;
    root->right = n2;
    n1->left = n3;
    n1->right = n4;
    n3->left = n5;
    //n2->right = n6;

    cout << sol.kthSmallest(root, 6);
    return 0;
}