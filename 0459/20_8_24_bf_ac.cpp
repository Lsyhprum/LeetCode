#include <iostream>

using namespace std;

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string pattern = ""; pattern += s[0];

        int front = 1, tail = 1, last_change = 1;
        int count = 0;
        while(tail < s.size()){
            if(count == 0){
                if(pattern[count] == s[tail]){
                    count ++;
                }else{
                    pattern += s[tail];
                }
            }else{
                if(pattern[count] == s[tail]){
                    count ++;
                    if(count == pattern.size()){
                        front = tail + 1;
                        count = 0;
                    }
                }else{
                    for(int i = last_change; i <= tail; i ++){
                        pattern
                    }
                }
            }

            tail ++;
        }
    }
};

int main(){
    Solution sol;

    cout << sol.repeatedSubstringPattern("aabaaba");
    return 0;
}