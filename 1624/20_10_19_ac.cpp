#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        unordered_map<char, int> mp;

        int dist = -1;
        for(int i = 0; i < s.size(); i ++) {
            if(mp.find(s[i]) == mp.end()) mp[s[i]] = i;
            else dist = max(dist, i - mp[s[i]] - 1);
        }

        return dist;
    }
};

int main() {
    Solution sol;

    std::cout << sol.maxLengthBetweenEqualCharacters("cabbac");
    
    return 0;
}