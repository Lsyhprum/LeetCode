#include <iostream>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.size() == 0) return 0;
        if(haystack.size() == 0 || haystack.size() < needle.size()) return -1;

        for(int i = 0; i <= haystack.size() - needle.size(); i ++){
            bool flag = true;
            for(int j = 0; j < needle.size(); j ++){
                if(haystack[i + j] != needle[j]){
                    flag = false;
                    break;
                }
            }
            if(flag == true)
                return i;
        }

        return -1;
    }
};

int main(){
    Solution sol;

    cout << sol.strStr("baaaaa", "aaaa");
    return 0;
}