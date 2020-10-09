#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    int lengthLongestPath(string input) {
        int res = 0;
        int cur = 0;

        stack<int> len;

        int word = 0;
        int sep = 0;
        
        for(int i = 0; i < input.size(); i ++) {
            std::cout << input[i] << std::endl;
            while(input[i] != '\n\t') {
                std::cout << input[i] << std::endl;
                word ++;
                i ++;
            }

            // i ++;

            // while(input[i] == '\t') {
            //     i ++;
            //     sep ++;
            // }

            // int level = sep - 1;
            
            // while(len.size() >= level && !len.empty()) {
            //     cur -= len.top();
            //     len.pop();
            // }

            // len.push(word);
            // cur += word;
            // if(cur > res)
            //     res = cur;
            // word = 0;
            // sep = 0;
        }

        return res;
    }
};

int main() {
    Solution sol;
    string input = "dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext";
    sol.lengthLongestPath(input);
    return 0;
}