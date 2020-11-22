#include <iostream>

using namespace std;

class Solution {
public:
    string getSmallestString(int n, int k) {
        string s; s.resize(n);

        int max = 26;

        for(int i = n - 1; i > 0; i --) {
            if(k - i >= 26) {
                s[i] = 'a' + 26 - 1;
                k -= 26;
            } else {
                s[i] = 'a' + (k - i) - 1;
                k -= (k-i);
            }
        }

        s[0] = 'a' + k - 1;

        return s;
    }
};

int main() {
    Solution s;

    std::cout << s.getSmallestString(5, 5);

    return 0;
}