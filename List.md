# List

## Linked List

[2. 两数相加](https://leetcode-cn.com/problems/add-two-numbers/) : [solution]()

[445. 两数相加 II](https://leetcode-cn.com/problems/add-two-numbers-ii/) : [solution]()

[24. 两两交换链表中的节点](https://leetcode-cn.com/problems/swap-nodes-in-pairs/) : [solution]()

[206. 反转链表](https://leetcode-cn.com/problems/reverse-linked-list/) : [solution]()

[141. 环形链表](https://leetcode-cn.com/problems/linked-list-cycle/) : [solution]()

### Merge

[21. 合并两个有序链表](https://leetcode-cn.com/problems/merge-two-sorted-lists/) : [solution]()

[23. 合并K个升序链表](https://leetcode-cn.com/problems/merge-k-sorted-lists/) : [solution]()

[147. 对链表进行插入排序](https://leetcode-cn.com/problems/insertion-sort-list/) : [solution]()

[148. 排序链表](https://leetcode-cn.com/problems/sort-list/) : [solution]()

## Util

```cpp
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
```