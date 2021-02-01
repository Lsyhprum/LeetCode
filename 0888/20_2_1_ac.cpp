#include <iostream>
#include <numeric>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
        int sumA = accumulate(A.begin(), A.end(), 0);
        int sumB = accumulate(B.begin(), B.end(), 0);
        int delta = (sumA - sumB) / 2;
        unordered_set<int> rec(A.begin(), A.end());
        vector<int> ans;
        for (auto& y : B) {
            int x = y + delta;
            if (rec.count(x)) {
                ans = vector<int>{x, y};
                break;
            }
        }
        return ans;
    }
};

int main() {

    Solution sol;
    vector<int> A = {1, 1};
    vector<int> B = {2, 2};

    for(int i : sol.fairCandySwap(A, B))
        std::cout << i << std::endl;

    return 0;
}