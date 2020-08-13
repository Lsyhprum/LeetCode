#include <iostream>
#include <vector>

using namespace std;

// time complexity : O(N)
// memory complexity : O(N)
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/**
 *          5
 *       6      8
 *            4
 *              7 
 * 
 * inorder : 6 5 4 7 8
 *             _  _
 * 
 **/
// BST 特点 ： 中序有序
// 题目特点 ： 仅有两个异常点，且不会改变结构  
//              ----> 只需找到中序遍历中两个异常点交换，其他点无需移动
//    
// 思路 ： 
//      1. 通过中序遍历寻找到异常点 O(N)
//      2. 寻找到两个异常点后交换
class Solution {
public:
    void recoverTree(TreeNode* root) {
        vector<TreeNode*> history;
        int pos = -1;
    
        if(!inorder(root, history, pos)){
            exchange(history[pos], history[pos + 1]);
        }
        
    }

private:
    bool inorder(TreeNode* root, vector<TreeNode*>& history, int& pos){
        if(root){
            if(inorder(root->left, history, pos)){
                return true;
            }
           
            int len = history.size();
            if(len != 0 && root->val < history[len -1]->val){
                if(pos != -1){
                    // 第二次出现异常点
                    exchange(history[pos], root);
                    return true;
                }else{
                    // 第一次出现异常点
                    pos = len - 1;
                }
            }
                
            history.emplace_back(root);

            if(inorder(root->right, history, pos)){
                return true;
            }
        }

        return false;
    }

    void exchange(TreeNode*& a, TreeNode*& b){
        //cout << "exchange " << a->val << " " << b->val << endl;
        int tmp = a->val;
        a->val = b->val;
        b->val = tmp;
    }
};

void inorder(TreeNode* root){
    if(root){
        inorder(root->left);
        cout << root->val << endl;
        inorder(root->right);
    }
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