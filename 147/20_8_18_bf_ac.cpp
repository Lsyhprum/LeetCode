#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// time complexity : O(N^2), 7.71%
// memory complexity : O(1)
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return head;

        ListNode dummy(0);
        dummy.next = head;

        ListNode* tail = &dummy;

        while(tail->next){
            ListNode* ptr = &dummy;
            while(ptr->next != tail->next && ptr->next->val < tail->next->val){
                ptr = ptr->next;
            }

            ListNode *tmp = tail->next;
            tail->next = tail->next->next;

            tmp->next = ptr->next;
            ptr->next =tmp;

            if(ptr->next == tail->next){
                tail = tail->next;
            }
        }

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
    vector<int> v = {2, 1};
    ListNode* node = vec2LinkedList(v);

    ListNode* list = sol.insertionSortList(node);

    while(list){
        cout << list->val << endl;
        list = list->next;
    }

    return 0;
}