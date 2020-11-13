#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head == nullptr) return head;

        ListNode* pre_odd = head;
        ListNode* post_odd = head->next;

        while(post_odd != nullptr && post_odd->next != nullptr) {
            ListNode* node = post_odd->next;

            post_odd->next = node->next;
            node->next = pre_odd->next;
            pre_odd->next = node;

            post_odd = post_odd->next;
            pre_odd = pre_odd->next;
        }

        return head;
    }
};

int main() {
    Solution sol;

    ListNode *node = new ListNode(2);
    ListNode *node1 = new ListNode(1);
    ListNode *node2 = new ListNode(3);
    ListNode *node3 = new ListNode(5);
    ListNode *node4 = new ListNode(6);
    ListNode *node5 = new ListNode(4);
    ListNode *node6 = new ListNode(7);
    node->next = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = nullptr;
    node4->next = node5;
    node5->next = node6;
    node6->next = nullptr;

    ListNode *v = sol.oddEvenList(node);
    while(v) {
        std::cout << v->val << " ";
        v = v->next;
    }

    return 0;
}