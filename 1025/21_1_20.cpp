#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool divisorGame(int N) {
        return N % 2 == 0;
    }
};

int main() {

    Solution sol;

    std::cout << sol.divisorGame(77);

    return 0;
}