#include <iostream>
#include <vector>

using namespace std;

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// time complexity : O(NlogN), 79.08%
// memory complexity : O(1), 99.54%
class Solution {
  public:
    ListNode *sortList(ListNode *head) {
        if (!head || head->next == nullptr)
            return head;

        int len = 1;
        ListNode *cur = head;
        while (cur = cur->next)
            ++len;

        ListNode dummy(0);
        dummy.next = head;
        ListNode *l;
        ListNode *r;
        ListNode *tail;

        for (int n = 1; n < len; n <<= 1) {
            cur = dummy.next;
            tail = &dummy;
            while (cur) {
                l = cur;
                r = split(l, n);
                cur = split(r, n);
                auto merged = merge(l, r);
                tail ->next = merged.first;
                tail = merged.second;
            }
        }

        return dummy.next;
    }

  private:
    ListNode *split(ListNode *head, int n) {
        while(--n && head){
            head = head->next;
        }

        ListNode* rest = head ? head->next : nullptr;
        if(head) head->next = nullptr;
        return rest;
    }

    pair<ListNode*, ListNode*> merge(ListNode *l1, ListNode *l2){
        ListNode dummy(0);
        ListNode *tail = &dummy;

        while(l1 && l2){
            if(l1->val > l2->val) swap(l1, l2);

            tail->next = l1;
            l1 = l1->next;
            tail = tail->next;
        }
        tail->next = l1 ? l1 : l2;
        while(tail->next) tail = tail->next;
        return {dummy.next, tail};
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

int main() {
    Solution sol;
    vector<int> v1 = {4, 2, 1, 3};
    ListNode* l1 = vec2LinkedList(v1); 
    ListNode* node = sol.sortList(l1);

    while(node){
        cout << node->val << endl;
        node = node ->next;
    }
    return 0;
}