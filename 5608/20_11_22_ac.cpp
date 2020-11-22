#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        sort(tasks.begin(), tasks.end(), [](vector<int> a, vector<int> b) {
            if((a[1] - a[0]) == (b[1] - b[0])) return a[0] < b[0];
            return (a[1] - a[0]) < (b[1] - b[0]);
        });

        // for(int i = 0; i < tasks.size(); i ++) {
        //     std::cout << tasks[i][0] << " " << tasks[i][1] << std::endl;
        // }
        int res = tasks[0][1];
        for(int i = 1; i < tasks.size(); i ++) {
            res += tasks[i][0];
        }

        if(res < tasks[tasks.size() - 1][1]) return tasks[tasks.size() - 1][1];

        return res;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> v1 = {{1, 1}, {1, 3}};
    // 2 2 1 2 1
    // 8, 9 -> 9
    // 10, 11 -> 19
    // 1, 3 -> 20
    // 2, 4 -> 22
    // 10, 12 -> 32
    //vector<vector<int>> v = {{1, 3}, {2, 4}, {10, 11}, {10, 12}, {8, 9}};
    // 6, 6, 6, 6, 6, 6
    // 1, 7 -> 7
    // 2, 8 -> 9
    // 3, 9 -> 12
    // 4, 10 ->16
    // 5, 11 -> 21
    // 6, 12 -> 27
    vector<vector<int>> v2 = {{1, 7}, {2, 8}, {3, 9}, {4, 10}, {5, 11}, {6, 12}};
    
    std::cout << sol.minimumEffort(v1);
    return 0;
}