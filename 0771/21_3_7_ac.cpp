#include <iostream>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_set<char> set;

        for(char c : jewels) {
            set.insert(c);
        }

        int res = 0;
        for(char c : stones) {
            if(set.find(c) != set.end()) {
                res ++;
            }
        }

        return res;
    }
};

int main() {

    Solution sol;

    std::cout << sol.numJewelsInStones("aAAAA", "AAAAA");
    return 0;
}