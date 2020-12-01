## 二分查找

[35. 搜索插入位置](https://leetcode-cn.com/problems/search-insert-position/)

[367. 有效的完全平方数](https://leetcode-cn.com/problems/valid-perfect-square/)

我的理解：目标可通过左右两个条件限制，且不需要准确位置时使用

以下均讨论左右闭区间：

* 基本二分查找

```cpp
int binary_search(int[] nums, int target) {
    int left = 0, right = nums.length - 1; 
    while(left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] < target) {
            left = mid + 1;
        } else if (nums[mid] > target) {
            right = mid - 1; 
        } else if(nums[mid] == target) {
            // 直接返回
            return mid;
        }
    }
    // 直接返回
    return -1;
}
```

34. 在排序数组中查找元素的第一个和最后一个位置

704.

* 寻找左边界二分查找
```cpp
int left_bound(int[] nums, int target) {
    int left = 0, right = nums.length - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] < target) {
            left = mid + 1;
        } else if (nums[mid] > target) {
            right = mid - 1;
        } else if (nums[mid] == target) {
            // 别返回，锁定左侧边界
            right = mid - 1;
        }
    }
    // 最后要检查 left 越界的情况
    if (left >= nums.length || nums[left] != target)
        return -1;
    return left;
}
```

278.

* 寻找右边界二分查找
```cpp
int right_bound(int[] nums, int target) {
    int left = 0, right = nums.length - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] < target) {
            left = mid + 1;
        } else if (nums[mid] > target) {
            right = mid - 1;
        } else if (nums[mid] == target) {
            // 别返回，锁定右侧边界
            left = mid + 1;
        }
    }
    // 最后要检查 right 越界的情况
    if (right < 0 || nums[right] != target)
        return -1;
    return right;
}
```

162.

**易错**：

1. left + (right - left) / 2 防止溢出

2. 左闭右开 left < right  左闭右闭 left <= right

3. 左闭右开 right = mid 左闭右闭 right = mid - 1

4. 寻找左边界

    * if(nums[mid] == target) right = mid;

    * 左闭右闭
        * 由于 while 终止条件为 left == right + 1, 若不存在target, 右溢出

5. 寻找右边界

    * if(nums[mid] == target) left = mid;

6. **判断返回 left 还是 right**

    * 根据返回较大值还是较小值决定

## 快速幂

50.

