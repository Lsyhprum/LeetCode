#include <iostream>

using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(s.size() == 0) return true;
        if(t.size() == 0) return false;

        int pos = 0;

        for(int i = 0; i < t.size(); i ++) {
            if(t[i] == s[pos]) {
                pos ++;

                if(pos == s.size()) return true;
            }
        }

        return false;
    }
};

int main() {
    Solution sol;

    std::cout << sol.isSubsequence("abc", "abc") << std::endl;
    return 0;
}