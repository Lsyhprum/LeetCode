#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode* dummy = new ListNode(INT_MIN);
        ListNode* first = dummy;

        while(head) {
            while(first->next && head->val >= first->next->val) {
                first = first->next;
            }

            ListNode* node = head;
            head = head->next;

            node->next = first->next;
            first->next = node;

            first = dummy;

            // node = dummy->next;

            // while(node) {
            //     std::cout << node->val << " ";
            //     node = node->next;
            // }
            // std::cout << std::endl;
        }

        return dummy->next;
    }
};

int main() {
    Solution sol;
    // ListNode* node4 = new ListNode(0);
    // ListNode* node3 = new ListNode(4);
    // node3->next = node4;
    // ListNode* node2 = new ListNode(3);
    // node2->next = node3;
    ListNode* node1 = new ListNode(5);
    // node1->next = node2;
    ListNode* head = new ListNode(-1);
    head->next = node1;

    ListNode *node = sol.insertionSortList(head);

    while(node) {
        std::cout << node->val << " ";
        node = node->next;
    }

    return 0;
}