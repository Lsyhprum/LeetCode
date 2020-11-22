#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        vector<char> w1;
        vector<char> w2;
        
        for(string s : word1) {
            for(char c : s) {
                w1.push_back(c);
            }
        }

        for(string s : word2) {
            for(char c : s) {
                w2.push_back(c);
            }
        }

        if(w1.size() != w2.size()) return false;

        for(int i = 0; i < w1.size(); i ++) {
            if(w1[i] != w2[i]) return false;
        }
        return true;
    }
};

int main() {
    Solution sol;
    vector<string> v1 = {"abc", "d", "defg"};
    vector<string> v2 = {"abcddefgh"};
    std::cout << sol.arrayStringsAreEqual(v1, v2);
    return 0;
}