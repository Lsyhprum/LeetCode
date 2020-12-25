#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

// Time complexity : O(N), Space complexity : O(N)
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s = "";
        ser_inorder(root, s);
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int pos = 0;
        TreeNode* root = nullptr;
        de_inorder(&root, data, pos);

        return root;
    }
  
private:

    void ser_inorder(TreeNode* root, string &s) {
        if(root == nullptr) {
            s.append("#");
            return;
        }

        stringstream ss;
        ss << root->val << ",";
        s.append(ss.str());
        ser_inorder(root->left, s);
        ser_inorder(root->right, s);
    }

    void de_inorder(TreeNode** root, string &s, int &pos) {
        if(s[pos] == '#') {
            pos ++;
            return;
        }

        int end = pos;
        while(s[end] != ',') {
            end ++;
        }

        stringstream ss;

        ss << s.substr(pos, end);

        pos = end + 1;

        int val;
        ss >> val;
        *root = new TreeNode(val);

        de_inorder(&((*root)->left), s, pos);
        de_inorder(&((*root)->right), s, pos);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));

void InOrder(TreeNode *root) {
    if(root == nullptr) {
        return ;
    }

    std::cout << root->val << std::endl;
    InOrder(root->left);
    InOrder(root->right);
}

int main() {
    TreeNode *o4 = new TreeNode(-523);
    TreeNode *o3 = new TreeNode(423);
    TreeNode *o2 = new TreeNode(-323);
    TreeNode *o1 = new TreeNode(223);
    TreeNode *origin = new TreeNode(-123);
    origin -> right = o1;
    o1 -> right = o2;
    o2 -> right = o3;
    o3 -> right = o4;

    Codec ser;
    string s = ser.serialize(origin);
    std::cout << s << std::endl;

    Codec deser;
    TreeNode* root = deser.deserialize(s);

    InOrder(root);

    return 0;
}