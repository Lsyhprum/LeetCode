#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// Time complexity : O(Nlog(N))
class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        vector<int> res(A.size());

        int left = 0, right = A.size() - 1;


        sort(res.begin(), res.end());

        return res;
    }
};

int main() {
    Solution sol;
    vector<int> v = {-4, -1, 0, 3, 10};
    vector<int> res = sol.sortedSquares(v);

    for(int i : res) 
        std::cout << i << std::endl;

    return 0;
}