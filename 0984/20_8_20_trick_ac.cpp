#include <iostream>

using namespace std;

// time complexity : O(N), 100.00%
// memory complexity : O(1), 30.15%
class Solution {
public:
    string strWithout3a3b(int A, int B) {
        char a = 'a';
        char b = 'b';

        if(A < B){
            swap(a, b);
            swap(A, B);
        }

        string res = "";
        while(A || B){
            if(A > 0) { res += a; A --; }
            if(A > B) { res += a; A --; }
            if(B > 0) { res += b; B --; }
        }

        return res;
    }
};

int main(){
    Solution sol;
    cout << sol.strWithout3a3b(100, 100);
    return 0;
}