#include <iostream>
#include <string>

using namespace std;

// time complexity : O(N), faster than 93.76% of C++ online submissions for Add Binary.
// memory complexity : O(N), less than 77.22% of C++ online submissions for Add Binary.
class Solution {
public:
    string addBinary(string a, string b) {
        int aLen = a.size(), bLen = b.size();
        int len = aLen > bLen ? aLen : bLen;

        string res = "";
        int flag = 0;
        for(int i = 0; i < len; i ++){
            int ac = 0, bc = 0;
            if(i < aLen)
                ac = a[aLen - 1 - i] - '0';
            
            if(i < bLen)
                bc = b[bLen - 1 - i] - '0';
            
            int val = ac + bc + flag;
            flag = val / 2;
            res.insert(0, to_string(val % 2));
            // cout << val <<endl;
            // cout << val % 2 << endl;
            // cout << res << endl;
        }
        if(flag)
            res.insert(0, to_string(flag));
        
        return res;
    }
};

int main(){
    Solution sol;
    cout << sol.addBinary("1", "1") << endl;

    return 0;
}