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
        
        queue<Node*> s;
        s.push(root);
        int cur_level_num = 1;
        int next_level_num = 0;

        Node *front = nullptr; 
        while(!s.empty()) {
            Node *node = s.front();
            s.pop();

            if(front != nullptr) {
                front->next = node;
            }
            front = node;

            if(node->left) s.push(node->left);
            if(node->right) s.push(node->right);

            next_level_num += 2;

            cur_level_num --;
            if(cur_level_num == 0) {
                cur_level_num = next_level_num;
                next_level_num = 0;
                front->next = nullptr;
                front = nullptr;
            }
        }

        return root;
    }
};

int main() {
    Solution sol;
    // Node *node4 = new Node(4);
    // Node *node5 = new Node(5);
    // Node *node6 = new Node(6);
    // Node *node7 = new Node(7);

    // Node *node2 = new Node(2, node4, node5, nullptr);
    // Node *node3 = new Node(3, node6, node7, nullptr);

    Node *node1 = new Node(1, nullptr, nullptr, nullptr);

    sol.connect(nullptr);

    Node *node = node1;
    while(node) {
        std::cout << node->val << std::endl;
        node = node->next;
    }

    return 0;
}