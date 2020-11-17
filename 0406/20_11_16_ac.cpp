#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// [[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]
// [[5,0], [7,0], [5,2], [6,1], [4,4], [7,1]]


class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        // 50 70 61 71 52 44
        // 44 50 52 61 70 71
        std::vector<std::vector<int>> res;

        std::sort(people.begin(), people.end(), [](const vector<int> &a, vector<int> &b) {
            if(a[0] == b[0]) return a[1] < b[1];
            return a[0] > b[0];
        });

        for(vector<int> pair : people) {
            if(res.size() <= pair[1]) 
                res.push_back(pair);
            else
                res.insert(res.begin() + pair[1], pair); 
        }

        return res;
    }
};

int main() {

    Solution sol;
    //{7, 0}, {4, 4}, {7, 1}, {5, 0}, {6, 1}, {5, 2}
    vector<vector<int>> v = {};
    vector<vector<int>> res = sol.reconstructQueue(v);
    for(int i = 0; i < res.size(); i ++)
        std::cout << res[i][0] << " " << res[i][1] << std::endl;
    return 0;
}