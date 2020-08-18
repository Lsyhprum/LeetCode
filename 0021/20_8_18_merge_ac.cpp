#include <iostream>
#include <vector>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// time complexity : O(N1 + N2), 50.92%
// memory complexity : O(1), 28.89%
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode *tail = &dummy;

        while(l1 && l2){
            if(l1->val > l2->val) swap(l1, l2);
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
    vector<int> v2 = {};
    ListNode* l1 = vec2LinkedList(v1);
    ListNode* l2 = vec2LinkedList(v2);
    ListNode* node = sol.mergeTwoLists(l1, l2);

    while(node){
        cout << node->val << endl;
        node = node ->next;

    }
    return 0;
}