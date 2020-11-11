class Solution:
    def trap(self, height: List[int]) -> int:
        n = len(height)

        # 边界条件
        if n == 0:
            return 0

        res = 0

        # 初始化左右指针
        left, right = 0, n - 1
        # max_left 记录 height[0..left] 中最高柱子高度
        # max_right 记录 height[right..end] 中最高柱子高度
        max_left, max_right = height[left], height[right]

        while left < right:
            # 更新 max_left, max_right
            if height[left] > max_left:
                max_left = height[left]
            if height[right] > max_right:
                max_right = height[right]

            # 基于短板效应，选取最高柱子高度较低一侧的可达水柱高度加入结果
            if max_left < max_right:
                res += max_left - height[left]
                left += 1
            else:
                res += max_right - height[right]
                right -= 1

        return res