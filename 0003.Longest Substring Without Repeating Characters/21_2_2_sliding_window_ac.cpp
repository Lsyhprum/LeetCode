#include <iostream>
#include <algorithm>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if(n == 0) return 0;
        
        int maxn = 0, tmpn = 0;
        int left = 0, right = 0;
        unordered_set<char> container;

        int pos = 0;
        while(right < n) {
            //std::cout << left << " ";
            if(container.find(s[right]) == container.end()) {
                container.insert(s[right]);
                tmpn ++;
                right ++;
            } else {
                container.clear();
                left ++;
                right = left + 1;
                container.insert(s[left]);
                tmpn = 1;
            }
            maxn = max(maxn, tmpn);
            //std::cout << maxn << std::endl;
        }

        return maxn;
    }
};

int main() {
    Solution sol;

    std::cout << sol.lengthOfLongestSubstring("aaaaaab");
    return 0;
}