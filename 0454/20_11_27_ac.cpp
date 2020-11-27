#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int, int> ab;
        unordered_map<int, int> cd;

        for(int i : A) {
            for(int j : B) {
                ab[i + j] += 1;
            }
        }

        for(int i : C) {
            for(int j : D) {
                cd[i + j] += 1;
            }
        }


        int res = 0;

        for(auto i : ab) {
            //std::cout << i.first << " " << i.second << std::endl;
            int aim = 0 - i.first;
            if(cd.count(aim) != 0) {
                res += (i.second * cd[aim]);
            }
        }

        return res;
    }
};

int main() {
    Solution sol;

    vector<int> a = {1, 1};
    vector<int> b = {1, 1};
    vector<int> c = {-1, -1};
    vector<int> d = {-1, -1};
    std::cout << sol.fourSumCount(a, b, c, d) << std::endl;
    return 0;
}