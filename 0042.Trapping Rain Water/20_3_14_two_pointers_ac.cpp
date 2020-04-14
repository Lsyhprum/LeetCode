# include <iostream>
# include <algorithm>
# include <vector>

using namespace std;

class Solution {
public:
    int maxContainer(vector<int>& height, int start, int end){
        if(start >= end - 1) return 0;

        int max_left = start;
        int max_right = end;
        int left = start;
        int right = end;

        while(left < right){
            if(height[left] > height[max_left]) max_left = left;
            if(height[right] > height[max_right]) max_right = right;

            if(height[left] > height[right]){
                right --;
            }else{
                left ++;
            }
        }
        //cout << max_left << " " << max_right << endl;
        int area = 0;
        int h = min(height[max_left], height[max_right]);
        for(int i = max_left + 1; i < max_right; i ++){
            area += (h - height[i]);
        }
        //cout << area << endl;

        return area + maxContainer(height, start, max_left) + maxContainer(height, max_right, end); 
    }

    int trap(vector<int>& height) {
        return maxContainer(height, 0, height.size()-1);
    }
};

int main(){
    Solution sol;
    vector<int> v = {2, 98, 99, 100, 97, 106, 2};
    cout << sol.trap(v) << endl;
    return 0;
}