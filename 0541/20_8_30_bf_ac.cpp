#include <iostream>

using namespace std;

class Solution {
public:
    string reverseStr(string s, int k) {
        int left = 0, right = s.size() > k ? k-1 : s.size() - 1;
        int flag = true;

        while(left < s.size()){
            //cout << s << endl;
            if(flag){
                int tmp_left = left, tmp_right = right;
                while(tmp_left < tmp_right){
                    swap(s[tmp_left], s[tmp_right]);

                    tmp_left ++;
                    tmp_right --;
                }
            }

            flag = !flag;
            left = right + 1;
            right = right + k >= s.size() ? s.size()-1 : right + k;
        }
        return s;
    }

};

int main(){
    Solution sol;
    cout << sol.reverseStr("abcdefg", 6);
    return 0;
}