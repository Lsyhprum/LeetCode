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

        queue<Node*> q;
        q.push(root);

        while(!q.empty()) {
            int levelNum = q.size(); 
            std::cout << levelNum << std::endl;

            Node* node = q.front();
            //std::cout << node->val << "->";
            q.pop();
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);

            for(int i = 1; i < levelNum; i ++ ) {
                Node* tmp = q.front();
                //std::cout << tmp->val << "->";
                q.pop();
                if(tmp->left) q.push(tmp->left);
                if(tmp->right) q.push(tmp->right);

                node->next = tmp;
                node = tmp;
            }
            //std::cout << node->val << "->";
            //std::cout << std::endl;
            node->next = nullptr;
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