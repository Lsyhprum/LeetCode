#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        priority_queue<pair<unsigned, int>> q;

        for(int i = 0; i < K; i ++) {
            q.push(pair<unsigned, int>(points[i][0] * points[i][0] + points[i][1] * points[i][1], i));
        }

        for(int i = K; i < points.size(); i ++) {
            unsigned dist = points[i][0] * points[i][0] + points[i][1] * points[i][1];
            if(dist < q.top().first) {
                q.pop();
                q.push(pair<unsigned, int>(dist, i));
            }
        }

        vector<vector<int>> res;

        while(!q.empty()) {
            res.push_back(points[q.top().second]);
            q.pop();
        }

        return res;
    }
};

int main() {
    Solution sol;

    vector<vector<int>> v = {{3, 3}, {5, -1}, {-2, 4}, {10000, 10000}};
    for(auto i : sol.kClosest(v, 2)) {
        std::cout << i[0] << " " << i[1] << std::endl;
    }

    return 0;
}