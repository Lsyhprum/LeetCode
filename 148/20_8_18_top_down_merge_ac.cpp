#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// time complexity : O(NlogN), 79.08%
// memory complexity : O(logN), 63.99%
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return head;

        ListNode *slow = head, *fast = head->next;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode *mid = slow->next;
        slow->next = nullptr;

        return  merge(sortList(head), sortList(mid));
    }

    ListNode* merge(ListNode *l1, ListNode *l2){
        ListNode dummy(0);
        ListNode *tail = &dummy;

        while(l1 && l2){
            if(l1->val > l2->val){
                swap(l1, l2);
            }

            tail->next = l1;
            l1 = l1->next;
            tail = tail->next;
        }

        if(l1) tail->next = l1;
        if(l2) tail->next = l2;

        return dummy.next;
    }
};

ListNode* vec2LinkedList(vector<int> v){
    ListNode dummy(0);
    ListNode *ptr = &dummy;

    for(int i : v){
        ListNode *node = new ListNode(i);
        ptr->next = node;
        ptr = ptr->next;     
    }

    return dummy.next;
}

int main(){
    Solution sol;
    vector<int> v1 = {};
    ListNode* l1 = vec2LinkedList(v1); 
    ListNode* node = sol.sortList(l1);

    while(node){
        cout << node->val << endl;
        node = node ->next;

    }
    return 0;
}