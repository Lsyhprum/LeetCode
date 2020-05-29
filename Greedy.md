
# 简单贪心

455.

# 区间贪心

* 从区间集合 intvs 中选择一个区间 x，这个 x 是在当前所有区间中 **结束最早** 的（end 最小）。
* 把所有与 x 区间相交的区间从区间集合 intvs 中删除。
* 重复步骤 1 和 2，直到 intvs 为空为止。之前选出的那些 x 就是最大不相交子集。

```cpp
public int intervalSchedule(int[][] intvs) {
    if (intvs.length == 0) return 0;
    // 按 end 升序排序
    Arrays.sort(intvs, new Comparator<int[]>() {
        public int compare(int[] a, int[] b) {
            return a[1] - b[1];
        }
    });
    // 至少有一个区间不相交
    int count = 1;
    // 排序后，第一个区间就是 x
    int x_end = intvs[0][1];
    for (int[] interval : intvs) {
        int start = interval[0];
        if (start >= x_end) {
            // 找到下一个选择的区间了
            count++;
            x_end = interval[1];
        }
    }
    return count;
}
```

**易错:**
1. 判断区间是否为 0
2. 若区间不为 0, 至少一个区间不相交

435.

452.


