#include <iostream>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        int lenA = a.size();
        int lenB = b.size();
        int len = lenA > lenB ? lenA : lenB;

        string res = "";
        int flag = 0;
        for(int i = len - 1; i >= 0; i --){
            int tmp = a[i] - '0' + b[i] - '0' + flag
        }    
    }
};

int main(){
    Solution sol;

    string a = "11";
    string b = "1";

    cout << sol.addBinary(a, b) << endl;
    return 0;
}