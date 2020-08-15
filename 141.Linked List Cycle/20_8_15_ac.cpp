# include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };
  
// time complexity : O(N), 99.86%
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head) return false;

        ListNode *fast = head->next;
        ListNode *slow = head;

        while(fast && fast->next){
            if(slow != fast){
                //cout << slow->val << " " << fast->val << endl;
                slow = slow->next;
                fast = fast->next->next;
            }else{
                //cout << slow << " " << fast << endl;
                return true;
            }
        }

        return false;
    }
};

int main(){
    Solution sol;
    ListNode node1 = ListNode(1);
    ListNode node2 = ListNode(2);
    ListNode node3 = ListNode(0);
    ListNode node4 = ListNode(-4);
    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;
    node4.next = &node2;

    cout << sol.hasCycle(&node1) << endl;
    return 0;
}