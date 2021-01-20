#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void hanota(vector<int>& A, vector<int>& B, vector<int>& C) {
        move(A.size(), A, B, C);
    }

private:
    void move(int n, vector<int> &A, vector<int> &B, vector<int> &C) {
        if(n > 0) {
            move(n - 1, A, C, B);
            C.push_back(A.back());
            A.pop_back();
            move(n - 1, B, A, C);
        }
    }
};

int main() {

    Solution sol;

    vector<int> A = {3, 2, 1, 0};
    vector<int> B = {};
    vector<int> C = {};
    sol.hanota(A, B, C);
    for(int i : C) {
        std::cout << i << std::endl;
    }

    return 0;
}