#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == nullptr || head->next == nullptr)
            return head;
        
        ListNode* prior = head;
        ListNode* rear = head;

        while(rear){
            if(rear->val == prior->val){
                rear = rear->next;
            }else{
                prior->next = rear;
                prior = prior->next;
            }
        }

        prior->next = nullptr;
        return head;
    }
};

int main(){

    // ListNode* p2 = new ListNode(3);
    // ListNode* p1 = new ListNode(2, p2);
    ListNode* head = new ListNode(1);

    Solution sol;
    ListNode* res = sol.deleteDuplicates(head);
    while(res){
        cout << res ->val << endl;
        res = res->next;
    }

    return 0;
}