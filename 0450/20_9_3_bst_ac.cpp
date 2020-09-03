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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == nullptr) return root;

        TreeNode* node = root;
        TreeNode* parent = nullptr;
        
        while(node != nullptr && node->val != key){
            if(key > node->val){
                parent = node;
                node = node->right;
            }else{
                parent = node;
                node = node->left;
            }
        }

        if(node == nullptr) return root;
        if(node->left == nullptr && node->right == nullptr){
            if(parent == nullptr) return nullptr;

            if(parent->left == node) parent->left = nullptr;
            else parent->right = nullptr;
        }else{
            deleteRoot(node, parent);
        }

        return root;
    }

    void deleteRoot(TreeNode*& root, TreeNode* parent){
        parent = root;
        TreeNode *pre = root->left;
        if(root->left == nullptr){
            pre = root->right;
            while(pre->left){
                parent = pre;
                pre = pre->left;
            }
            root->val = pre->val;
            
            if(pre->right != nullptr) 
                deleteRoot(pre, parent);
            else {
                if(parent->left == pre)
                    parent->left = nullptr;
                else
                    parent->right = nullptr;
            }
        }else{
            while(pre->right){
                parent = pre;
                pre = pre->right;
            }
            root->val = pre->val;

            if(pre->left != nullptr) 
                deleteRoot(pre, parent);  
            else {
                if(parent->left == pre)
                    parent->left = nullptr;
                else
                    parent->right = nullptr;
            } 
        } 
    }
};