#include <iostream>

using namespace std;

// Time complexity : O(n), faster than 64.91% of C++ online submissions for Same Tree.
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == nullptr && q == nullptr)
            return true;

        if(p && q && p->val == q->val){
            bool flag = isSameTree(p->left, q->left) 
                            && isSameTree(p->right, q->right);
            return flag;
        }else{
            return false;
        }
    }
};

int main(){
    TreeNode* n2 = new TreeNode(2);
    TreeNode* n3 = new TreeNode(1);

    TreeNode* p = new TreeNode(1, n2, n3);

    TreeNode* n4 = new TreeNode(1);
    TreeNode* n5 = new TreeNode(2);
    TreeNode* q = new TreeNode(1, n4, n5);

    Solution sol;
    cout << sol.isSameTree(p, q);

    return 0;
}