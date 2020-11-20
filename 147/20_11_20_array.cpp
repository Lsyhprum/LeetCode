#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;


// Time complexity : O(NlogN), 76.79%
// Memory complexity : O(N), 5.08%
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        vector<int> array;
        while(head) {
            array.push_back(head->val);
            head = head->next;
        }
        sort(array.begin(), array.end());

        ListNode* dummy = new ListNode(INT_MIN);
        ListNode* pre = dummy;
        
        for(int i = 0; i < array.size(); i ++) {
            ListNode* node = new ListNode(array[i]);
            pre->next = node;
            pre = pre->next;
        }

        return dummy->next;
    }
};

int main() {
    Solution sol;
    ListNode* node4 = new ListNode(0);
    ListNode* node3 = new ListNode(4);
    node3->next = node4;
    ListNode* node2 = new ListNode(3);
    node2->next = node3;
    ListNode* node1 = new ListNode(5);
    node1->next = node2;
    ListNode* head = new ListNode(-1);
    head->next = node1;

    ListNode *node = sol.insertionSortList(head);

    while(node) {
        std::cout << node->val << " ";
        node = node->next;
    }

    return 0;
}