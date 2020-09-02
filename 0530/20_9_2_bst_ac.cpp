#include <iostream>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    int getMinimumDifference(TreeNode* root) {
        int diff = INT_MAX;
        
        InOrder(root, diff);

        return diff;
    }

private:
    TreeNode* pre = nullptr;
    void InOrder(TreeNode* node, int &diff){
        if(node == nullptr) return ;

        InOrder(node->left, diff);

        if(pre != nullptr && node->val - pre->val < diff){
            cout << node->val << " " << pre->val << endl;
            diff = node->val - pre->val;
        }
        pre = node;
            
        InOrder(node->right, diff);
    }
};

int main(){
    cout << (INT_MAX == -(INT_MIN+1)) << endl;
    return 0;
}