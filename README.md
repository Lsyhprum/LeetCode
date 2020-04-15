[stack](https://github.com/Lsyhprum/LeetCode/blob/master/Stack.md)

[queue]()

[tree]()


[two pointers]()



[]

[dp]()


















DP 步骤

1. 写出递归
2. 递归记忆化
3. 初步dp
4. 滚动数组



## 左右指针



## 滑动窗口





## string

### 大数运算

415.Add Strings

43.Multiply Strings

方法：数据化为 string，模拟手动运算，使用 char 或 int 型数组保存每位信息（上一位进位+该位对应相加结果），注意所有位数相加结束后进位的处理

乘法可分解为简单乘法与加法，逐位相乘,注意将乘积叠加至正确位置


# 回溯思想

解决一个回溯问题，实际上就是一个决策树的遍历过程。你只需要思考 3 个问题：

1、路径：也就是已经做出的选择。

2、选择列表：也就是你当前可以做的选择。

3、结束条件：也就是到达决策树底层，无法再做选择的条件。

回溯算法的框架：

```python
result = []
def backtrack(路径, 选择列表):
    if 满足结束条件:
        result.add(路径)
        return
    
    for 选择 in 选择列表:
        做选择
        backtrack(路径, 选择列表)
        撤销选择
```

其核心就是 for 循环里面的递归，在递归调用之前「做选择」，在递归调用之后「撤销选择」

回溯算法的一个特点，不像动态规划存在重叠子问题可以优化，回溯算法就是纯暴力穷举，复杂度一般都很高。

其实想想看，回溯算法和动态规划是不是有点像呢？我们在动态规划系列文章中多次强调，动态规划的三个需要明确的点就是「状态」「选择」和「base case」，是不是就对应着走过的「路径」，当前的「选择列表」和「结束条件」？

某种程度上说，动态规划的暴力求解阶段就是回溯算法。只是有的问题具有重叠子问题性质，可以用 dp table 或者备忘录优化，将递归树大幅剪枝，这就变成了动态规划。而今天的两个问题，都没有重叠子问题，也就是回溯算法问题了，复杂度非常高是不可避免的。



## 搜索：DFS、BFS

## 子集、排列、组合

排除重复的排列-》组合

子集问题可以利用数学归纳思想，假设已知一个规模较小的问题的结果，思考如何推导出原问题的结果。也可以用回溯算法，要用 start 参数排除已选择的数字。

组合问题利用的是回溯思想，结果可以表示成树结构，我们只要套用回溯算法模板即可，关键点在于要用一个 start 排除已经选择过的数字。

排列问题是回溯思想，也可以表示成树结构套用算法模板，关键点在于使用 contains 方法排除已经选择的数字，前文有详细分析，这里主要是和组合问题作对比。-

17. 22. 46. 组合 DFS








LRU  146. LRU Cache



