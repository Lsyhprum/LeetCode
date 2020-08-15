#include <iostream>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// time complexity : O(N), 95.92%
// memory complexity : O(1), 47.28%
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        // 1-2-3-4-5-nullptr
        // 3-2-1-4-5-nullptr
        // 5-4-3-2-1-nullptr
        if(!head || head->next == nullptr) return head;

        ListNode d(-1);
        d.next = head;
        head = &d;

        ListNode *p1 = head->next;
        ListNode *p2 = head->next->next;

        while(p2){
            p1->next = p2->next;
            p2->next = head->next;
            head->next = p2;

            p2 = p1->next;
        }

        return head->next;
    }
};

int main(){
    Solution sol;
    // ListNode* node5 = new ListNode(5);
    // ListNode* node4 = new ListNode(4, node5);
    // ListNode* node3 = new ListNode(3, node4);
    ListNode* node2 = new ListNode(2, nullptr);
    ListNode* node1 = new ListNode(1, node2);

    ListNode* node = sol.reverseList(node1);

    while(node){
        cout << node->val << endl;
        node = node->next;
    }

    return 0;
}