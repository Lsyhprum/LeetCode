#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

class Solution {
public:
    int largestPerimeter(vector<int>& A) {
        sort(A.begin(), A.end());

        for(int i = A.size() - 1; i > 1; i --) {
            for(int j = i - 1; j > 0; j --) {
                for(int k = j - 1; k >= 0; k --) {
                    //std::cout << i << " " << j << " " << k << std::endl;
                    if(A[j] + A[k] > A[i]) {
                        return A[j] + A[k] + A[i];
                    }
                }
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