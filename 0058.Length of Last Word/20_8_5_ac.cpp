#include <iostream>

using namespace std;

// Time complexity : less than O(n), faster than 91.72% of C++ online submissions for Length of Last Word.
class Solution {
public:
    int lengthOfLastWord(string s) {
        int res = 0;
        int len = s.length();

        for(int i = s.length() - 1; i >= 0; i --){
            if(s[i] == ' ' && res != 0)
                return res;
            
            if(s[i] != ' ')
                res ++;
        }

        return res;
    }
};

int main(){
    Solution sol;
    cout << sol.lengthOfLastWord("a aabbbccc");
}