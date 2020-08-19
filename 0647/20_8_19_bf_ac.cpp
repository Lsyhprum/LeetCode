#include <iostream>
#include <vector>

using namespace std;

// time complexity : O(N^2), 7.25%
// memory complexity : O(1), 82.24%
class Solution {
public:
    int countSubstrings(string s) {
        int res = s.size();

        if(res == 0 || res == 1) return res;

        for(int i = 0; i < s.size() - 1; i ++){
            for(int j = i + 1; j < s.size(); j ++){
                int left = i;
                int right = j;
 
                while(left < right && s[left] == s[right]){
                    left ++;
                    right --;
                }
                if(left >= right)
                    res ++;
            }
        }

       return res;
    }
};

int main(){
    Solution sol;
    string s = "abccbaabv";
    cout << sol.countSubstrings(s) ;
    return 0;
}