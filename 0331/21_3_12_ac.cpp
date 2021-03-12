#include <iostream>

using namespace std;

class Solution {
public:
    bool isValidSerialization(string preorder) {
        int pos = -1;

        return helper(preorder, pos) && pos == preorder.size() - 1;
    }

private:
    bool helper(const string& preorder, int& pos) {
        pos ++;
        std::cout << preorder[pos] << std::endl;

        if(pos >= preorder.size()) return false;
        if(preorder[pos] == '#') {
            if(pos + 1 < preorder.size()) {
                pos ++;
            }
            return true; 
        }
        // 整数
        while(pos < preorder.size() && preorder[pos] >= '0' && preorder[pos] <= '9') {
            pos ++;
        }

        return helper(preorder, pos) && helper(preorder, pos);
    }
};

int main() {
    Solution sol;
    std::cout << sol.isValidSerialization("#,#,#");
    return 0;
}