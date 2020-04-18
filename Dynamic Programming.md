# 动态规划

* 什么问题可以使用动态规划？

动态规划的一般形式就是求极值，最长递增子序列呀，最小编辑距离呀等等。

动态规划本质就是穷举，只不过存在**重叠子结构**、**最优子结构**，且必须列出**状态转移方程**才能正确穷举。

重叠子结构优化方法：备忘录 / dp table

* 备忘录

我们可以造一个「备忘录」，每次算出某个子问题的答案后别急着返回，先记到「备忘录」里再返回；每次遇到一个子问题先去「备忘录」里查一查，如果发现之前已经解决过这个问题了，直接把答案拿出来用，不要再耗时去计算了。

自顶向下

* dp table

自底向上

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





























DP 步骤

1. 写出递归
2. 递归记忆化
3. 初步dp
4. 滚动数组


# LIS


求子数组、子字符串、求极值 ---> dp
***139.



