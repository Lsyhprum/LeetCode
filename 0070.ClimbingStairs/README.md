
1. 明确状态

第几级台阶

2. 定义 dp 数组

dp[i] 第 i 级台阶共有几种上到此台阶方法

3. 明确选择

dp[i] = dp[i-1] + dp[i-2]

4. 明确base case

dp[0] = 1
dp[1] = 1

5. 优化


备忘录 / dp table 


易错：dp_table = n+ 1