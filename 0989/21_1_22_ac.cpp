#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> addToArrayForm(vector<int>& A, int K) {
        if(K == 0) return A;
        
        int pos = A.size() - 1;
        unsigned flag = 0;
        while(K || flag) {
            int k_end = K % 10;

            int origin = 0;
            if(pos >= 0) {
                origin = A[pos];
            }

            int sum = origin + k_end + flag;
            flag = sum / 10;

            if(pos < 0) {
                A.insert(A.begin(), sum % 10);
            } else {
                A[pos] = sum % 10;
            }

            K /= 10;
            pos --;
        }

        return A;
    }
};

int main() {
    Solution sol;
    vector<int> A = {9,9,9,9,9,9,9,9,9,9};
    vector<int> res = sol.addToArrayForm(A, 1);
    for(int i : res) {
        std::cout << i << std::endl;
    }
    return 0;
}