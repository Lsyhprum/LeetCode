# include <iostream>
# include <algorithm>
# include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    vector<TreeNode*> nodes;

public:
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if (!s && !t) return true;
        if (!s || !t) return false;

        getDepth(s, getDepth(t, -1));

        for (TreeNode* n: nodes)
            if (identical(n, t))
                return true;

        return false;
    }

    int getDepth(TreeNode* r, int d) {
        if (!r)
            return -1;

        int depth = max(getDepth(r->left, d), getDepth(r->right, d)) + 1;

        // Check if depth equals required value
        // Require depth is -1 for tree t (only return the depth, no push)
        if (depth == d)
            nodes.push_back(r);

        return depth;
    }

    bool identical(TreeNode* a, TreeNode* b) {
        if (!a && !b) return true;
        if (!a || !b || a->val != b->val) return false;

        return identical(a->left, b->left) && identical(a->right, b->right);
    }
};

int main(){
    Solution sol;

    TreeNode *root = new TreeNode(3);
    TreeNode *n1 = new TreeNode(4);
    TreeNode *n2 = new TreeNode(5);
    TreeNode *n3 = new TreeNode(1);
    TreeNode *n4 = new TreeNode(2);
    TreeNode *n5 = new TreeNode(0);
    //TreeNode *n6 = new TreeNode(7);

    root->left = n1;
    root->right = n2;
    n1->left = n3;
    n1->right = n4;
    n3->left = n5;
    //n2->right = n6;

    TreeNode *root1 = new TreeNode(4);
    TreeNode *n11 = new TreeNode(1);
    TreeNode *n21 = new TreeNode(2);
    //TreeNode *n31 = new TreeNode(1);
    //TreeNode *n41 = new TreeNode(2);
    //TreeNode *n5 = new TreeNode(15);
    //TreeNode *n6 = new TreeNode(7);

    root1->left = n11;
    root1->right = n21;
    //n11->left = n31;
    //n11->right = n41;
    //n2->left = n5;
    //n2->right = n6;

    cout << sol.isSubtree(root, root1);


    return 0;
}