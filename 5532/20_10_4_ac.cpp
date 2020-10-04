#include <iostream>
#include <queue>

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
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode *> s;
        s.push(root);

        int cur = 1;
        int next = 0;
        int level = 0;
        int front = INT_MIN;
        while(!s.empty()) {
            TreeNode *node = s.front();
            s.pop();

            std::cout << level << " " << node->val << std::endl;
            if((level % 2 == 0 && node->val % 2 == 0) ||
                (level % 2 != 0 && node->val % 2 != 0)){
                return false;        
            }
            if((level % 2 == 0 && node->val <= front) || 
                    (level % 2 != 0 && node->val >= front)){
                return false;
            }

            cur --;

            if(node->left) {
                s.push(node->left);
                next ++;
            }
            if(node->right) {
                s.push(node->right);
                next ++;
            }

            front = node->val;

            if(cur == 0) {
                cur = next;
                next = 0;
                level ++;

                if(level % 2 == 0) {
                    front = INT_MIN;
                }else {
                    front = INT_MAX;
                }
            }
        }

        return true;
    }
};

int main() {
    Solution sol;
    // TreeNode *node = new TreeNode(3);
    // TreeNode *node1 = new TreeNode(5);
    // TreeNode *node2 = new TreeNode(7);

    // TreeNode *node3 = new TreeNode(9, node, node1);
    // TreeNode *node4 = new TreeNode(1, node2, nullptr);

    TreeNode *node5 = new TreeNode(1, nullptr, nullptr);

    // TreeNode *node6 = new TreeNode(9, nullptr, node3);
    // TreeNode *node7 = new TreeNode(10, node4, nullptr);
    // TreeNode *node8 = new TreeNode(4, node5, node6);
    // TreeNode *node9 = new TreeNode(1, node7, node8);
    std::cout << sol.isEvenOddTree(node5);
    return 0;
}