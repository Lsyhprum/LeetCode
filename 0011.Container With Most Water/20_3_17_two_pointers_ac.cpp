# include <iostream>
# include <algorithm>
# include <vector>

using namespace std;

//Runtime: 95.35%
class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int ans = -1;

        while(left < right){
            int val = (right - left) * min(height[left], height[right]);

            ans = max(ans, val);

            if(height[left] > height[right]){
                right --;
            }else{
                left ++;
            }
        }

        return ans;
    }
};

int main(){
    Solution sol;
    vector<int> v = {1,8,6,2,5,4,8,3,7};
    cout << sol.maxArea(v) << endl;
    return 0;
}