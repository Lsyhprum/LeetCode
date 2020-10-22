#include <iostream>

using namespace std;

class Solution {
public:
    bool isLongPressedName(string name, string typed) {

        int pos = 0;
        for(int i = 0; i < typed.size(); ) {
            if(name[pos ++] != typed[i ++]) return false;

            while(name[pos] == typed[i] && pos < name.size() && i < typed.size()) {
                pos ++;
                i ++;
            }

            while(typed[i - 1] == typed[i]) {
                i ++;
            }
        }

        std::cout << pos << std::endl;

        if(pos < name.size()) return false;

        return true;
    }
};

int main() {
    Solution sol;

    std::cout << sol.isLongPressedName("aa", "aab");
    return 0;
}