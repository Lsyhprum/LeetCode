#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool validMountainArray(vector<int>& A) {
        int len = A.size();

        if(len < 3) return false;

        bool inc = false, dec = false;

        for(int i = 0; i < A.size() - 1; i ++) {
            if(A[i + 1] > A[i]) {
                if(dec == false) {
                    inc = true;
                    continue;
                }else{
                    return false;
                }
            }else if(A[i + 1] < A[i]) {
                if(inc == true) {
                    dec = true;
                    continue;
                }else {
                    return false;
                }
            }else{
                return false;
            }
        }

        if(inc && dec)
            return true;
        return false;
    }
};

int main() {
    Solution sol;
    vector<int> v = {1, 2, 3, 4, 5, 1};
    std::cout << sol.validMountainArray(v);
    return 0;
}