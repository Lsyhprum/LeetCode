#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string S) {
        vector<int> res;
        unordered_map<char, int> mp;

        for(int i = 0; i < S.size(); i ++ ) {
            mp[S[i]] = i;
        }

        for(int i = 0, s = -1, e = 0; i < S.size(); i ++)
            if(i == (e = max(e, mp[S[i]])))
                res.push_back(i - s), s = i;

        return res;
    }
};

int main() {
    Solution sol;
    // 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14
    // e a e d c a a a d e  d  a  a  c  b
 
    vector<int> v = sol.partitionLabels("eaedcaaadedaacb");

    for(int i = 0; i < v.size(); i ++) {
        std::cout << v[i] << std::endl;
    }

    return 0;
}