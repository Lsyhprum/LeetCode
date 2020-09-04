#include <iostream>

using namespace std;

class Solution {
public:
    int countOdds(int low, int high) {
        // 8 8
        // 8 9
        // 8 10

        // 3 3
        // 3 4
        // 3 5
        // 3 7 
        // 3 8
        // 7 7
        return low % 2 == 0 ? (high - low + 1) / 2 : (high - low) / 2 + 1; 
    }
};

int main(){
    return 0;
}