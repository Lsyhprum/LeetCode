#include <iostream>
#include <stack>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return true;

        // 1 2 3 4 5
        // 1 2 3 4
        // 1 2 3 4 5 6
        ListNode* fast = head;
        ListNode* slow = head;

        stack<ListNode*> s;
        s.push(slow);

        while(fast->next && fast->next->next) {
            slow = slow->next;
            s.push(slow);
            fast = fast->next->next;
        }

        if(fast->next == nullptr)
            s.pop();

        while(slow->next) {
            //std::cout << s.top()->val << std::endl;
            if(s.top()->val == slow->next->val) {
                s.pop();
            }else{
                return false;
            }
            slow = slow->next;
        }

        return s.empty();
    }
};

int main() {
    Solution sol;

    ListNode *node4 = new ListNode(1);
    ListNode *node3 = new ListNode(2);
    node3->next = node4;
    ListNode *node2 = new ListNode(4);
    node2->next = node3;
    ListNode *node1 = new ListNode(2);
    node1->next = node2;
    ListNode *head = new ListNode(1);
    head->next = node1;

    std::cout << sol.isPalindrome(head);
    return 0;
}