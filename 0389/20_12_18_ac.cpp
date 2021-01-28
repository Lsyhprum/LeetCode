#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char, int> mp;

        for(char c : s) {
            mp[c] ++;
        }

        for(char c : t) {
            if(mp.find(c) == mp.end()) {
                return c;
            }

            mp[c] --;

            if(mp[c] < 0) {
                return c;
            }
        }

        return t[0];
    }  
};

int main() {
    Solution sol;

    std::cout << sol.findTheDifference("abcd", "abcde");
    return 0;
}