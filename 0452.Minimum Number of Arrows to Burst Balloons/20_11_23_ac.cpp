#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if(points.size() <= 1) return points.size();

        sort(points.begin(), points.end(), [](const vector<int> &a, const vector<int> &b) {
            if(a[0] == b[0]) return a[1] < b[1];
            return a[0] < b[0];
        });

        // for(int i = 0; i < points.size(); i ++) {
        //     std::cout << points[i][0] << " " << points[i][1] << std::endl;
        // }

        vector<vector<int>> stack;
        stack.push_back(points[0]);

        for(int i = 1; i < points.size(); i ++) {
            if(points[i][0] > stack.back()[1]) 
                stack.push_back(points[i]);
            else {
                stack.back()[0] = max(stack.back()[0], points[i][0]);
                stack.back()[1] = min(stack.back()[1], points[i][1]);
            }
                

            //std::cout << "---" << std::endl;
            //std::cout << stack[stack.size() - 1][0] << " " << stack[stack.size() - 1][1] << std::endl;
        }

        return stack.size();
    }
};

int main() {
    Solution sol;
    vector<vector<int>> v = {{9, 12}, {1, 10}, {4, 11}, {8, 12}, {3, 9}, {6, 9}, {6, 7}};
    std::cout << sol.findMinArrowShots(v);

    return 0;
}