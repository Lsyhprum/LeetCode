#include <iostream>
#include <map>
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

        map<int, pair<ListNode*, ListNode*>, less<int>> mp; 

        ListNode dummy(0);
        dummy.next = head;

        ListNode* tail = &dummy;

        while(tail->next){
            ListNode* ptr = tail;
            for(auto iter = mp.begin(); iter != mp.end(); iter ++){
                if(iter->first > tail->next->val){
                    ptr = iter->second.first;
                    break;
                }
            }

            if(ptr != tail){
                ListNode* tmp = tail->next;
                 
                tail->next = tail->next->next;

                tmp->next = ptr->next;
                mp[ptr->next->val].first = tmp;

                ptr->next = tmp;
                mp[tmp->val].first = ptr;
            }else{
                if(mp.find(tail->next->val) != mp.end()){
                    if(mp[tail->next->val].first > )
                    mp[tail->next->val].second = tail;
                }else{
                    mp[tail->next->val] = pair<ListNode*, ListNode*>(tail, tail);
                }
                
                tail = tail->next;
            }

            cout << "---------" << endl;

            for(auto iter = mp.begin(); iter != mp.end(); iter ++){
                cout << iter->first << endl;
                cout << "first " << iter->second.first->val << endl;
                if(iter->second.second != nullptr)
                    cout << "second " << iter->second.second->val << endl;
            }
            cout << "---------" << endl;
            
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
    vector<int> v = {5, 4, 1, 2, 1, -1};
    ListNode* node = vec2LinkedList(v);

    ListNode* list = sol.insertionSortList(node);

    while(list){
        cout << list->val << endl;
        list = list->next;
    }

    return 0;
}