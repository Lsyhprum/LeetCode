# Base

## Time complexity & Memory complexity

* 时间复杂度
* 空间复杂度
    * O(1) : 如果算法执行所需要的临时空间不随着某个变量n的大小而变化，即此算法空间复杂度为一个常量，可表示为 O(1)
    * O(N) : 


## Time complexity & Data size

* ACM或者互联网笔试题的时间限制是1秒或2秒。

* C++代码中的操作次数控制在 1e7, 1e8 为最佳。

|   复杂度   |  数量级     |   算法  |
|   ----     | ----       |    ----     | 
|   O(logN)  | n <= 10^18   |    最大公约数，快速幂    |     
|    O(N√N), O(logN)  | n <= 10^9    |    判断质数,快速幂 |
|   O(N), 常数小的 O(nlogn)  |  n <= 10^7    |     hash、双指针扫描、kmp、AC自动机、sort、树状数组、heap、dijkstra、spfa、线性筛素数    |     
|   O(NlogN)         |  n <= 10^5 |   各种排序，线段树，树状数组，set/map, heap, dijkstra+heap, spfa, 凸包，二分，求半平面交   |     
| O(N∗N√N)           |  n <= 10000|     块状链表             |    
| O(N^2), O(N^2*logN)|  n <= 1000 |     dp, 二分             |    
|   O(N^3)           |  n <= 100  |  floyd, dp               |   
|   O(2^N)           |  n <= 30   |  dfs+剪枝，状态压缩dp     |
|   O(N!)            |  n <= 10   |                          |



*参考*

[由数据范围反推算法复杂度以及算法内容——ACM](https://blog.csdn.net/qq_43827595/article/details/98844463?utm_medium=distribute.pc_relevant.none-task-blog-BlogCommendFromMachineLearnPai2-3.channel_param&depth_1-utm_source=distribute.pc_relevant.none-task-blog-BlogCommendFromMachineLearnPai2-3.channel_param)

