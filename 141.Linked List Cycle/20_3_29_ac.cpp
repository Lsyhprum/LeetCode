# include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };
  
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == NULL || head->next == NULL) return false;

        ListNode *fast = head;
        ListNode *slow = head;

        while(fast && fast -> next){         // 判空写法啰嗦
            fast = fast -> next -> next;
            slow = slow -> next;

            if(fast != NULL && fast == slow)
                return true;
        }

        return false;
    }
};

int main(){
    Solution sol;
    ListNode node1 = ListNode(1);
    ListNode node2 = ListNode(2);
    ListNode node3 = ListNode(0);
    // ListNode node4 = ListNode(-4);
    node1.next = &node1;
    //node2.next = &node3;
    // node3.next = &node4;
    // node4.next = &node2;


    cout << sol.hasCycle(&node1) << endl;
    return 0;
}