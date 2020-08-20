#include <iostream>

using namespace std;

// 
class Solution {
public:
    string strWithout3a3b(int A, int B) {
        string res = "";
        recursion(A, B, res);
        return res;
    }

    bool recursion(int A, int B, string &s){
        if(A == 0 && B == 0) return true;

        int tailA = 0, tailB = 0;
        if(s.size() > 0)
            s[s.size()-1] == 'a' ? (tailA += 1) : (tailB += 1); 
        
        if(s.size() > 1)
            s[s.size()-2] == 'a' ? (tailA += 1) : (tailB += 1);
        
        if(A > 0 && tailA != 2){
            s += 'a';
            if(recursion(A-1, B, s)){
                return true;
            }else{
                s.erase(s.end()-1);
            }
        }

        if(B > 0 && tailB != 2){
            s+= 'b';
            if(recursion(A, B-1, s)){
                return true;
            }else{
                s.erase(s.end()-1);
            }
        }

        return false;
    }
};

int main(){
    Solution sol;
    cout << sol.strWithout3a3b(10, 10);
    return 0;
}