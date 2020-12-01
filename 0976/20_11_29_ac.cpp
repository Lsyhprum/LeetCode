#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

class Solution {
public:
    int largestPerimeter(vector<int>& A) {
        sort(A.begin(), A.end());

        for(int i = A.size() - 1; i >= 2; i --) {
            if(A[i - 1] + A[i - 2] > A[i]) {
                return A[i - 1] + A[i - 2] + A[i];
            }
        }

        return 0;
    }   
};

int main() {
    Solution sol;
    vector<int> v = {1, 2, 1};
    std::cout << sol.largestPerimeter(v);
    return 0;
}