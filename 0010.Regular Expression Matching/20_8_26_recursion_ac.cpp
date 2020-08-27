#include <iostream>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        return isMatch(s.c_str(), p.c_str());
    }

private:
    bool isMatch(char *s, char *p){
        if(*p == '\0') return *s == '\0';
        
        // *.
        // *a
        // ..
        // .a
        // a.
        // aa
        // *@
        // .@
        // a@
        if(p[1] != '*' || p[1] == '\0'){
            if(*s == '\0') return false;

            if(*s == *p || *p == '.')
                return isMatch(s + 1, p +1);
            else
                return false;
        }else{
            // **
            // .*
            // a*

            int i = -1;
            while(i == -1 || s[i] == p[0] || p[0] == '.'){
                if(isMatch(s+i+1, p + 2)) return true;
                if(s[++i] == '\0') break;
            }
            return false;
        }

        return false;
    }
};

int main(){

    return 0;
}