#include <vector>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Time complexity : O(N)
// Memory complexity : O(N)
class Solution {
public:
    vector<int> findMode(TreeNode* root) {
        vector<int> res;
        if(root == nullptr) return res;

        int num = 0, max = 0;
        TreeNode *pre = nullptr;

        InOrder(root, pre, num, res, max);

        if(num > max){
            res.clear();
            res.push_back(pre->val);
            max = num;
        }else if(num == max){
            res.push_back(pre->val);
        }

        //cout << num << " " << pre->val << endl;

        return res;
    }

    void InOrder(TreeNode* node, TreeNode *&pre, int &num, vector<int> &res, int &max){
        if(node == nullptr)  return ;
        
        InOrder(node->left, pre, num, res, max);

        if(pre == nullptr) {
            pre = node;
            num ++;
        }
        else {
            if(pre->val == node->val){
                num ++;
            }else{
                if(num > max){
                    res.clear();
                    res.push_back(pre->val);
                    max = num;
                }else if(num == max){
                    res.push_back(pre->val);
                }
                pre = node;
                num = 1;
            }
        }

        InOrder(node->right, pre, num, res, max);
    }
};