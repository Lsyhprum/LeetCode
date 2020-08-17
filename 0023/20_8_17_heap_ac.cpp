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
        ListNode *dummy = new ListNode(0);
        ListNode *tail = dummy;

        auto cmp = [](ListNode *a, ListNode *b){return a->val > b->val;};
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> q(cmp);

        for(ListNode* list : lists){
            if(list){
                q.push(list);
                list = list->next;
            }
        }

        while(!q.empty()){
            tail->next = q.top(); q.pop();
            tail = tail->next;
            if(tail->next) q.push(tail->next);
        }

        return dummy->next;
        
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