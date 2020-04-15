# include <iostream>
# include <algorithm>
# include <vector>
# include <stack>

using namespace std;

// Brute-Force n^2
// 单调栈 减小搜索范围
// Runtime 88.75%
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> s;
        heights.emplace_back(0);

        int ans = 0;
        for(int i = 0; i < heights.size(); i ++){
            while(!s.empty() && heights[s.top()] >= heights[i]){
                int cur = s.top();
                s.pop();

                ans = max(ans, heights[cur] * (s.empty() ? i : (i - s.top() - 1)));
            }

            s.push(i);
        }

        return ans;
    }
};

int main(){
    Solution sol;

    vector<int> v = {2, 1, 5, 6, 2, 3};
    cout << sol.largestRectangleArea(v);
    return 0;
}