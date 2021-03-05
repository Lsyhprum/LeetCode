#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> res;

        int sum = 0;
        for(int i : nums) {
            sum += i;
            res.push_back(sum);
        }

        return res;
    }
};

int main() {
    return 0;
}