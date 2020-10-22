#include <iostream>
#include <queue>

using namespace std;


class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node* connect(Node* root) {
        if(root == nullptr) return nullptr;

        Node *last_head = root;
        Node *last_node = root;
        Node *front = new Node(-1);

        while(last_head->left) {
            while(last_node) {
                front->next = last_node->left;
                front = last_node->left;
                //std::cout << front << std::endl;
                front->next = last_node->right;
                front = last_node->right;
                //std::cout << front << std::endl;

                last_node = last_node->next;
            }
            
            last_head = last_head->left;
            last_node = last_head;
            front = new Node(-1);
        }

        return root;
    }
};

int main() {
    Solution sol;
    Node *node4 = new Node(4);
    Node *node5 = new Node(5);
    Node *node6 = new Node(6);
    Node *node7 = new Node(7);

    Node *node2 = new Node(2, node4, node5, nullptr);
    Node *node3 = new Node(3, node6, node7, nullptr);

    Node *node1 = new Node(1, node2, node3, nullptr);

    sol.connect(nullptr);

    Node *node = node2;
    while(node) {
        std::cout << node->val << std::endl;
        node = node->next;
    }

    return 0;
}