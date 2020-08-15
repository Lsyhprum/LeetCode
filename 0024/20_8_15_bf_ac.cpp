#include <iostream>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// time complexity : O(N), 65.14%
// memory complexity : O(N), 95.33%
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return head;

        ListNode* res = head->next;

        ListNode* p1 = nullptr;
        ListNode* p2 = head;
        while(p2 && p2->next){
            ListNode* tmp = p2->next;
            //cout << "p2 " << p2->val << " tmp " << tmp->val << endl; 
            p2->next = tmp->next;
            tmp->next = p2;
            if(p1 != nullptr){
                p1->next = tmp;
            }

            p1 = p2;
            p2 = p2->next;
        }

        return res;
    }
};

int main(){

    Solution sol;
    // ListNode* node5 = new ListNode(5);
    // ListNode* node4 = new ListNode(4, node5);
    // ListNode* node3 = new ListNode(3, node4);
    //ListNode* node2 = new ListNode(2);
    ListNode* node1 = new ListNode(1);

    ListNode* node = sol.swapPairs(node1);

    while(node){
        cout << node->val << endl;
        node = node->next;
    }

    return 0;
}