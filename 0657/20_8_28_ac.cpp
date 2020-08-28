#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    bool judgeCircle(string moves) {
        stack<char> row;
        stack<char> col;

        for(auto &s : moves){
            if(s == 'U'){
                if(col.empty() || col.top() == 'U')
                    col.push('U');
                else
                    col.pop();
            }

            if(s == 'D'){
                if(col.empty() || col.top() == 'D')
                    col.push('D');
                else
                    col.pop();
            }

            if(s == 'L'){
                if(row.empty() || row.top() == 'L')
                    row.push('L');
                else
                    row.pop();
            }

            if(s == 'R'){
                if(row.empty() || row.top() == 'R')
                    row.push('R');            
                else
                    row.pop();
            }
        }

        //cout << col.empty() << endl;
        return col.empty() && row.empty();
    }
};

int main(){

    Solution sol;

    cout << sol.judgeCircle("LRUD");
    return 0;
}