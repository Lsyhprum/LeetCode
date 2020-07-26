#include <iostream>
#include <queue>

using namespace std;

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
        if(root == NULL)
            return "";
        string pre;
        string post;
        TreeNode* p = root;
        PreOrder(p, pre);
        p = root;
        InOrder(p, post);

        return pre + "|" + post;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int split_num = data.find('|');
        string pre = data.substr(0, split_num);
        string in = data.substr(split_num + 1, 11);

        // 中左右
        // 左中右
        TreeNode res = BuildTree(pre, in, 0);

        return &res;
    }

private:
    TreeNode BuildTree(string pre, string in, int num){
        //base case

        //root
        TreeNode node = TreeNode(pre[0]);
        int pos = in.find(pre[0])
        node.left = BuildTree()


        int pos = in.find(pre[num]);   // 寻找根节点位置
        BuildTree(pre.substr())
    }

    TreeNode BuildTreeRecursion(string pre, string in, int num){

    }

    void PreOrder(TreeNode* root, string& res){
        if(root == nullptr) return;

        res.append(to_string(root->val));
        PreOrder(root->left, res);
        PreOrder(root->right, res);
    }

    void InOrder(TreeNode* root, string& res){
        if(root == nullptr) return;

        InOrder(root->left, res);
        res.append(to_string(root->val));
        InOrder(root->right, res);
    }
};

int main(){
    cout << "wtf" << endl;
    TreeNode root(1);
    TreeNode node1(2);
    TreeNode node2(3);
    root.left = &node1;
    root.right = &node2;
    TreeNode node3(4);
    TreeNode node4(5);
    node2.left = &node3;
    node2.right = &node4;

    Codec c;
    string res = c.serialize(&root);

    c.deserialize(res);

    return 0;
}
