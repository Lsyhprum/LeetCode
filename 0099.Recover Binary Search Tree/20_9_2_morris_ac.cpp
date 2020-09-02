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
        TreeNode *x = nullptr, *y = nullptr, *pred = nullptr, *predecessor = nullptr;

        while(root != nullptr){
            if(root->left != nullptr){
                predecessor = root->left;

                while(predecessor->right != nullptr && predecessor->right != root){
                    predecessor = predecessor->right;
                }

                if(predecessor->right == nullptr){
                    predecessor->right = root;
                    root = root->left;
                }else{
                    if(pred != nullptr && root->val < pred->val){
                        y = root;
                        if(x == nullptr)
                            x = pred;
                    }
                    pred = root;

                    predecessor->right = nullptr;
                    root = root->right;
                }
            }else{
                if(pred != nullptr && root->val < pred->val){
                    y = root;
                    if(x == nullptr) {
                        x = pred;
                    }
                }
                pred = root;
                root = root->right;
            }
        }
        swap(x->val, y->val);
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