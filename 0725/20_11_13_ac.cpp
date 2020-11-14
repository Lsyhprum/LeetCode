#include <iostream>
#include <vector>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        vector<ListNode*> head;
        vector<ListNode**> tail;
        for(int i = 0; i < k; i ++) {
            ListNode* ptr = root;
            ListNode** tmp_ptr = &root;
            head.push_back(ptr);
            tail.push_back(tmp_ptr);
        }

        if(root == nullptr || k == 1) return head;

        // 初始化
        for(int i = k - 1; i >= 0; i --) {
            int times = 0;
            while(*tail[i] && times <= i) {
                tail[i] = &((*(tail[i]))->next);
                times ++;
            }
        }
        
        // 确定分割链表位置
        while(*tail[k-1]) {
            for(int i = 0; i < k; i ++){
                int num = 0;
                while(*tail[i] && num <= i) {
                    tail[i] = &((*(tail[i]))->next);
                    num ++;
                }
            }
        }

        for(int i = 0; i < k; i ++) {
            if((*tail[i]))
                std::cout << (*tail[i])->val << " ";
            else
                std::cout << "wtf" << std::endl;
        }
        std::cout << std::endl;

        // 分割链表
        for(int i = 1; i < k; i ++) {
            if(*tail[i-1]) {
                head[i] = (*(tail[i-1]))->next;
                (*(tail[i-1]))->next = nullptr;
            } else {
                head[i] = nullptr;
            }
        }

        return head;
    }
};

int main() {
    Solution sol;

    ListNode* node  = new ListNode(1);
    ListNode* node1 = new ListNode(2);
    ListNode* node2 = new ListNode(3);
    ListNode* node3 = new ListNode(4);
    ListNode* node4 = new ListNode(5);
    ListNode* node5 = new ListNode(6);
    ListNode* node6 = new ListNode(7);
    ListNode* node7 = new ListNode(8);
    ListNode* node8 = new ListNode(9);
    ListNode* node9 = new ListNode(10);
    node->next = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = node6;
    node6->next = node7;
    node7->next = node8;
    node8->next = node9;
    node9->next = nullptr;

    vector<ListNode*> res = sol.splitListToParts(node, 3);

    for(int i = 0; i < res.size(); i ++) {
        while(res[i]){
            std::cout << res[i]->val << " ";
            res[i] = res[i]->next;
        }
        std::cout << std::endl;
    }

    return 0;
}