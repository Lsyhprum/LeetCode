# include <iostream>
# include <algorithm>
# include <stack>
# include <vector>

using namespace std;

// Runtime 36.99%
class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> s;  

        int ans = 0, mid, left;

        for(int i = 0; i < height.size(); i ++){
            while(!s.empty() && height[s.top()] < height[i]){
                mid = s.top();   // 可能容器底
                s.pop();

                if(s.empty()) break;    // 无左壁

                left = s.top();

                int h = min(height[left], height[i]) - height[mid];
                int w = i - left  - 1;
                ans += (h * w);
            }

            s.push(i);
        }

        return ans;
    }
};

int main(){
    Solution sol;
    vector<int> v = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout << sol.trap(v);
    return 0;
}