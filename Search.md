# Search

### BFS

* [1091. 二进制矩阵中的最短路径](https://leetcode-cn.com/problems/shortest-path-in-binary-matrix/)


#### BFS 模板

```
void BFS() {
    定义队列;
    定义备忘录，用于记录已经访问的位置；

    判断边界条件，是否能直接返回结果的。           // 剪枝 1

    将起始位置加入到队列中，同时更新备忘录。

    while (队列不为空) {
        获取当前队列中的元素个数。
        for (元素个数) {
            取出一个位置节点。                   
            判断是否到达终点位置。                // 剪枝 2
            获取它对应的下一个所有的节点。
            条件判断，过滤掉不符合条件的位置。     // 剪枝 3 
            新位置重新加入队列。
        }
    }
}
```

### Combination

* [17. 电话号码的字母组合](https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number/) 
    
    * [dfs + backtracking]()

    * [bfs]()

[]() : [solution]()

[]() : [solution]()

[77. Combinations](https://leetcode.com/problems/combinations/) : [solution]()

[78. Subsets](https://leetcode.com/problems/subsets/) : [solution]()

[90. Subsets II](https://leetcode.com/problems/subsets-ii/) : [solution]()

[301. Remove Invalid Parentheses](https://leetcode.com/problems/remove-invalid-parentheses/) : [solution]()

### Permutation

* [46. Permutations](https://leetcode.com/problems/permutations/)

* [47. 全排列 II](https://leetcode-cn.com/problems/permutations-ii/)

* [784. 字母大小写全排列](https://leetcode-cn.com/problems/letter-case-permutation/)

* [943. 最短超级串](https://leetcode-cn.com/problems/find-the-shortest-superstring/)

### Partition

* [698. 划分为k个相等的子集](https://leetcode-cn.com/problems/partition-to-k-equal-sum-subsets/)


### Note

* 通常数据规模小于 20 可使用
* 注意剪枝

* 包含重复数字，返回不重复搜索结果
    * 排序
    * 限制同一 level 上的相同数字只出现一次