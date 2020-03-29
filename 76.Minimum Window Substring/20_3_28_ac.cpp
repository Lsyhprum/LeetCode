# include <iostream>
# include <string>
# include <unordered_map>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        int left = 0, right = 0, start = 0, minLen = INT_MAX;
        string res;

        unordered_map<char, int> needs;
        unordered_map<char, int> windows;
        for(char c : t) needs[c] ++;

        int match = 0;

        while(right < s.size()){
            char c1 = s[right];
            if(needs.count(c1)){
                windows[c1] ++;
                if(windows[c1] == needs[c1]){
                    match ++;
                }
            }

            right ++;

            while(match == needs.size()){
                if(right - left  < minLen){
                    start = left;
                    minLen = right - left;
                }
                char c2 = s[left];
                if(needs.count(c2)){
                    windows[c2] --;
                    if(windows[c2] < needs[c2]){
                        match --;
                    }
                }
                left ++;
            }
        } 

        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};

int main(){
    Solution sol;

    cout << sol.minWindow("ADOBECODEBANC", "ABC") << endl;

    return 0;
}