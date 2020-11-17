#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.size() != word2.size()) return false;

        unordered_map<char, int> mp1;
        unordered_map<char, int> mp2;

        for(char c : word1) {
            mp1[c] ++;
        }
        for(char c : word2) {
            if(mp1.count(c) == 0) return false;
            mp2[c] ++;
        }

        vector<int> num1;

        for(auto iter : mp1) {
            num1.push_back(iter.second);
        }
        sort(num1.begin(), num1.end());

        vector<int> num2;
        for(auto iter : mp2) {
            num2.push_back(iter.second);
        }
        sort(num2.begin(), num2.end());

        for(int i = 0; i < num1.size(); i ++) {
            if(num1[i] == num2[i]){
                continue;
            }else{
                return false;
            }
        }

        return true;
    }
};

int main() {
    Solution sol;

    std::cout << sol.closeStrings("cabbba", "aabbss");
    return 0;
}