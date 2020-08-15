#include <iostream>
#include <stack>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// time complexity : O(N), 43.99%
// memory complexity : O(N), 52.66%
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> a;
        stack<int> b;

        while(l1){
            a.push(l1->val);
            l1 = l1->next;
        }

        while(l2){
            b.push(l2->val);
            l2 = l2->next;
        }

        ListNode* head = new ListNode(-1);
        int sum = 0;

        while(!a.empty() || !b.empty() || sum){
            sum += a.empty() ? 0 : a.top();
            sum += b.empty() ? 0 : b.top();
            
            if(!a.empty()) a.pop();
            if(!b.empty()) b.pop();

            ListNode* node = new ListNode(sum % 10);
            node->next = head->next;
            head->next = node;

            sum /= 10;
        }

        return head->next;
    }
};

int main(){
    Solution sol;
    ListNode* node0 = new ListNode(9);
    ListNode* node3 = new ListNode(9, node0);
    ListNode* node2 = new ListNode(9, node3);
    ListNode* node1 = new ListNode(9, node2);
    
    ListNode* node6 = new ListNode(1);
    ListNode* node5 = new ListNode(1, node6);
    ListNode* node4 = new ListNode(1, node5);

    ListNode* node = sol.addTwoNumbers(node1, node4);

    while(node){
        cout << node->val << endl;
        node = node->next;
    }
    return 0;
}