#include <iostream>
#include <unordered_map>

using namespace std;

class ThroneInheritance {
  public:
    struct Tree {
        string name;
        bool flag;
        Tree *left;  // 左孩子
        Tree *right; // 右兄弟

        Tree(string name_) : name(name_) {
            left = nullptr;
            right = nullptr;
            flag = true;
        }

        // Tree(string name_, Tree* son_, Tree* borther_) : name(name_),
        // left(son_), right(borther_) {}
    };

    Tree *root = nullptr;
    unordered_map<string, Tree *> map;

    ThroneInheritance(string kingName) {
        root = new Tree(kingName);

        map.insert(pair<string, Tree *>(kingName, root));
    }

    void birth(string parentName, string childName) {
        auto iter = map.find(parentName);
        Tree *parent = iter->second;

        Tree *node = new Tree(childName);
        map.insert(pair<string, Tree *>(childName, node));

        if (parent->left == nullptr) {
            parent->left = node;
        } else {
            Tree *tmp = parent->left;
            while (tmp->right != nullptr) {
                tmp = tmp->right;
            }
            tmp->right = node;
        }
    }

    void death(string name) {
        auto iter = map.find(name);
        Tree *node = iter->second;
        node->flag = false;
    }

    vector<string> getInheritanceOrder() {
        vector<string> res;

        Tree *node = root;
        PreOrder(node, res);

        return res;
    }

    void PreOrder(Tree *node, vector<string> &res) {
        if (node == nullptr)
            return;

        if (node->flag)
            res.push_back(node->name);

        PreOrder(node->left, res);
        PreOrder(node->right, res);
    }
};