#include <iostream>
#include <vector>
#include <queue>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


// time complexity : O(nklogk)
// memory complexity : O(k)
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return merge(lists, 0, lists.size()-1);
    }

private:
    ListNode* merge(vector<ListNode*>& lists, int l, int r){
        if(l > r) return nullptr;
        if(l == r) return lists[l];
        if(l + 1 == r) return mergeTwoLists(lists[l], lists[r]);

        int m = l + (r - l) / 2;
        auto l1 = merge(lists, l, m);
        auto l2 = merge(lists, m +1, r);

        return mergeTwoLists(l1, l2);
    }

    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2){
        ListNode dummy(0);
        ListNode* tail = &dummy;

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

int main(){
    Solution sol;
    ListNode *node3 = new ListNode(3);
    ListNode *node2 = new ListNode(2, node3);
    ListNode *node1 = new ListNode(1, node2);

    ListNode *node6 = new ListNode(6);
    ListNode *node5 = new ListNode(5, node6);
    ListNode *node4 = new ListNode(4, node5);

    ListNode *node8 = new ListNode(8);
    ListNode *node7 = new ListNode(7, node8);
    vector<ListNode*> lists = {node1, node4, node7};
    ListNode *res = sol.mergeKLists(lists);

    while(res){
        cout << res->val << endl;
        res = res->next;
    }

    return 0;
}