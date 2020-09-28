#include <iostream>
#include <queue>

using namespace std;

// Definition for a Node.
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
        if(root == nullptr) return root;

        Node *cur = root;
        while(cur != nullptr) {
            Node *dummy = new Node(0);
            Node *pre = dummy;
            while(cur != nullptr) {
                if(cur->left) {
                    pre->next = cur->left;
                    pre = pre->next;
                }

                if(cur->right) {
                    pre->next = cur->right;
                    pre = pre->next;
                }

                cur = cur->next;
            }
            
            cur = dummy->next;
        }
        
        return root;
    }
};

int main() {
    Solution sol;

    Node* left1 = new Node(4);
    Node* right1 = new Node(5);
    Node* right2 = new Node(7);

    Node* left = new Node(2, left1, right1, nullptr);
    Node* right = new Node(3, nullptr, right2, nullptr);
    Node* root = new Node(1, left, right, nullptr);
    
    Node* node = sol.connect(root);
    return 0;
}