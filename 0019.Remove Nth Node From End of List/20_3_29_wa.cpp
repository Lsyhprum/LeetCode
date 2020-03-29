# include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };
  
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL) return NULL;

        ListNode *fast = head + n;        // *p + 1 ? 注意链表与数组区别
        ListNode *slow = head;

        if(fast == NULL) return head->next;
        
        while(fast->next){              // 链表循环终止判断
            fast = fast->next;
            slow = slow->next;
        }

        slow->next = slow->next->next;

        return head;
    }
};

int main(){

    Solution sol;
    ListNode node1 = ListNode(1);
    ListNode node2 = ListNode(2);
    ListNode node3 = ListNode(3);
    ListNode node4 = ListNode(4);
    ListNode node5 = ListNode(5);
    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;
    node4.next = &node5;

    cout << sol.removeNthFromEnd(&node1, 2) << endl;
}