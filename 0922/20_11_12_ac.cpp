#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        vector<int> odd_false;
        vector<int> even_false;

        for(int i = 0; i < A.size(); i ++) {
            if(i % 2 == 0) {
                if(A[i] % 2 != 0) {
                    odd_false.push_back(i);
                }
            } else {
                if(A[i] % 2 == 0) {
                    even_false.push_back(i);
                }
            }
        }

        int size = odd_false.size();
        for(int i = size - 1; i >= 0; i --) {
            swap(A[odd_false[i]], A[even_false[i]]);
            odd_false.pop_back();
            even_false.pop_back();
        }

        return A;
    }
};

int main() {
    Solution sol;
    vector<int> v = {1, 2, 3, 4};
    vector<int> v1 = sol.sortArrayByParityII(v);
    for(int i : v1) {
        std::cout << i << " ";
    }
    return 0;
}