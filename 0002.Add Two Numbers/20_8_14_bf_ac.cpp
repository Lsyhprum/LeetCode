#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// time complexity : O(N), faster than 65.43% of C++ online submissions for Add Two Numbers.
// memory complexity : O(N), less than 16.56% of C++ online submissions for Add Two Numbers.
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1 == nullptr || l2 == nullptr)
            return nullptr;

        ListNode* head = new ListNode(-1);
        ListNode* ptr = head;
        int flag = 0;

        while(l1 || l2){
            int val1 = 0, val2 = 0;
            if(l1)
                val1 = l1->val;
            
            if(l2)
                val2 = l2->val;

            int sum = val1 + val2 + flag;

            ListNode* node = new ListNode(sum % 10);
            ptr->next = node;
            ptr = ptr->next;

            //cout << node->val << endl;

            flag = sum / 10;

            if(l1)
                l1 = l1->next;
            if(l2)
                l2 = l2->next;
        }

        if(flag){
            ListNode* node = new ListNode(flag);
            ptr->next = node;
        }

        return head->next;

    }
};

int main(){

    Solution sol;
    ListNode* node3 = new ListNode(9);
    ListNode* node2 = new ListNode(9, node3);
    ListNode* node1 = new ListNode(9, node2);
    
    ListNode* node6 = new ListNode(1);
    ListNode* node5 = new ListNode(0, node6);
    // ListNode* node4 = new ListNode(5, node5);

    ListNode* node = sol.addTwoNumbers(node1, node5);

    while(node){
        cout << node->val << endl;
        node = node->next;
    }
    return 0;
}