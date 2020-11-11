#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        map<unsigned, vector<vector<int>> > mp;

        for(auto p : points) {
            unsigned dist = p[0] * p[0] + p[1] * p[1];

            mp[dist].emplace_back(p);
        }

        vector<vector<int>> res;

        int num = 0;
        auto iter = mp.begin();
        while(num < K) {
            if((*iter).second.empty() && iter != mp.end())
                iter ++;
            res.push_back((*iter).second.back());
            (*iter).second.pop_back();
            num ++;
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