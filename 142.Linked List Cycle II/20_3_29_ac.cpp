# include <iostream>

using namespace std;

 struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };
 
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL) return NULL;

        ListNode *fast = head;
        ListNode *slow = head;

        while(fast->next && fast->next->next){
            fast = fast->next->next;
            slow = slow->next;

            if(fast == slow){
                // 存在环
                slow = head;
                while(slow != fast){
                    slow = slow->next;
                    fast = fast->next;
                }
                return fast;
            }
        }

        return NULL;
    }
};

int main(){
    Solution sol;
    ListNode node1 = ListNode(1);
    //ListNode node2 = ListNode(2);
    //ListNode node3 = ListNode(0);
    //ListNode node4 = ListNode(-4);
    //node1.next = &node2;
    //node2.next = &node1;
    //node3.next = &node4;
    //node4.next = &node2;

    cout << sol.detectCycle(&node1)->val << endl;
    return 0;
}