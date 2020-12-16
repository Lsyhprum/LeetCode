#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        if(n<10) return n;
        string s=to_string(n);
        int flag=s.size();
        for(int i=s.size()-2;i>=0;i--){
            if(s[i]>s[i+1]){flag=i+1;s[i]--;}
        }
        for(int i=flag;i<s.size();i++) s[i]='9';
        return stoi(s);
    }
};
int main() {
    Solution sol;

    std::cout << sol.monotoneIncreasingDigits(120);
    return 0;
}