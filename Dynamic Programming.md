# DP

* [53. 最大子序和](https://leetcode-cn.com/problems/maximum-subarray/)

* [509. 斐波那契数](https://leetcode-cn.com/problems/fibonacci-number/)

* [70. 爬楼梯](https://leetcode-cn.com/problems/climbing-stairs/) : [solution]()

* [338. 比特位计数](https://leetcode-cn.com/problems/counting-bits/)

* [746. 使用最小花费爬楼梯](https://leetcode-cn.com/problems/min-cost-climbing-stairs/) : [solution]()

* [198. 打家劫舍](https://leetcode-cn.com/problems/house-robber/) : [solution]()

* [213. 打家劫舍 II](https://leetcode-cn.com/problems/house-robber-ii/)
    * [环状排列]()

* [91. 解码方法](https://leetcode-cn.com/problems/decode-ways/)
    * [solution]()

* [322. 零钱兑换](https://leetcode-cn.com/problems/coin-change/)

* [518. 零钱兑换 II](https://leetcode-cn.com/problems/coin-change-2/)
    * []()


## 0-1 背包系列问题

## 数位 dp

* 适用：数位 dp 适用于在给定区间 [A, B] 内，符合条件 f(i) 的数 i 的个数。条件 f(i) 与数的大小无关，而与数的组成有关。



### 动态规划模板

* 方法流程 ： 暴力递归搜索 -> 带备忘录的递归搜索（自顶向下） -> 动态规划（自下而上）-> 动态规划（状态压缩）
* 思考流程 ： 明确状态 -> 明确 dp 数组含义 -> 明确状态转移 

```cpp
# 初始化 base case
dp[0][0][...] = base
# 进行状态转移
for 状态1 in 状态1的所有取值：
    for 状态2 in 状态2的所有取值：
        for ...
            dp[状态1][状态2][...] = 求最值(选择1，选择2...)
```

* Search -> Search with memo (重叠子问题) -> 


* 什么问题可以使用动态规划？

动态规划的一般形式就是求极值，最长递增子序列呀，最小编辑距离呀等等。

动态规划本质就是穷举，只不过存在**重叠子问题**、**最优子结构**，且必须列出**状态转移方程**才能正确穷举。

重叠子结构优化方法：备忘录 / dp table

* 备忘录 (自顶向下)

我们可以造一个「备忘录」，每次算出某个子问题的答案后别急着返回，先记到「备忘录」里再返回；每次遇到一个子问题先去「备忘录」里查一查，如果发现之前已经解决过这个问题了，直接把答案拿出来用，不要再耗时去计算了。

（时间复杂度：子问题个数乘以子问题需要时间）

自底向上 dptable

反过来的备忘录


eg：斐波那契

带备忘录的递归, 

```cpp
int helper(vector<int>& memo, int n) {
    // base case 
    if (n == 1 || n == 2) return 1;
    // 已经计算过
    if (memo[n] != 0) return memo[n];
    memo[n] = helper(memo, n - 1) + 
                helper(memo, n - 2);
    return memo[n];
}
```

dp table

```cpp
int fib(int N) {
    vector<int> dp(N + 1, 0);
    // base case
    dp[1] = dp[2] = 1;
    for (int i = 3; i <= N; i++)
        dp[i] = dp[i - 1] + dp[i - 2];
    return dp[N];
}
```

* 最优子结构

子问题之间不是相互独立的，但总问题可以通过子问题获取最优结果（求最值）

* 状态转移方程

    * 遍历的过程中，所求状态必须是已经计算出来的
    * 遍历的终点必须是存储结果的位置




思维框架：

明确【状态】 -> 定义 dp 数组含义 -> 明确【选择】 -> 明确 base case

eg:

>给你 k 种面值的硬币，面值分别为 c1, c2 ... ck，每种硬币的数量无限，再给一个总金额 amount，问你最少需要几枚硬币凑出这个金额，如果不可能凑出，算法返回 -1 。

[状态]：硬币数量无限，唯一状态就是目标金额 amount
dp 函数定义：当前目标金额 n, 需要最少 dp(n) 个硬币凑出金额
【选择】：

```
def coinChange(coins: List[int], amount: int):
    def dp(n):
        for coin in coins:
            res = min(res, 1 + dp(n - coin))
        return res
    return dp(amount)
```

明确base case:

if n == 0: return 0
if n < 0 : return -1

时间复杂度：子问题总数*每个子问题时间

* 备忘录优化子问题总数 / dp table 消除重叠子问题

列出动态转移方程，就是在解决“如何穷举”的问题。之所以说它难，一是因为很多穷举需要递归实现，二是因为有的问题本身的解空间复杂，不那么容易穷举完整。

备忘录、DP table 就是在追求“如何聪明地穷举”。用空间换时间的思路，是降低时间复杂度的不二法门，除此之外，试问，还能玩出啥花活？

70. 注意 dp_table[n+1]

198. why base case 不同


*参考*：

[第一章、动态规划系列](https://labuladong.gitbook.io/algo/dong-tai-gui-hua-xi-lie)


























DP 步骤

1. 写出递归
2. 递归记忆化
3. 初步dp
4. 滚动数组


# LIS


求子数组、子字符串、求极值 ---> dp
***139.



