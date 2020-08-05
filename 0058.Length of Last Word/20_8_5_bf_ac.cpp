#include <iostream>

using namespace std;

// Time complexity : O(n), faster than 21.72% of C++ online submissions for Length of Last Word.
class Solution {
public:
    int lengthOfLastWord(string s) {
        int res = 0;
        int len = s.length();


        for(int i = s.length() - 1; i >= 0; i --){
            if(s[i] == ' ') 
                len --;
            else
                break;
        }

        for(int i = 0; i < len; i ++){
            if(s[i] == ' ')
                res = 0;
            else 
                res ++;
        }

        return res;
    }
};

int main(){
    Solution sol;
    cout << sol.lengthOfLastWord("   ad saf sf sdf    ");
}