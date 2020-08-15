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
        int flag = 0;

        while(!a.empty() || !b.empty()){
            int vala = 0, valb = 0;
            if(!a.empty()){
                vala = a.top();
                a.pop();
            }

            if(!b.empty()){
                valb = b.top();
                b.pop();
            }
            int tmp = vala + valb + flag;

            ListNode* node = new ListNode(tmp % 10);
            node->next = head->next;
            head->next = node;
            flag = tmp / 10;
        }

        if(flag){
            ListNode* node = new ListNode(flag);
            node->next = head->next;
            head->next = node;
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