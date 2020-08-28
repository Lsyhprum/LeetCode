#include <iostream>
#include <vector>

using namespace std;

// time complexity : O(2^(l+r))
// memory complexity : 
class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        // check whether a input string is valid
        // right must le than left
        
        // compute min number of unbalanced ')' and unbalanced '('

        // avoid duplications

        int unbalanced_left = 0, unbalanced_right = 0;
        int left = 0, right = 0;
        for(auto &c : s){
            if(c == '(') left ++;

            if(c == ')') {
                right ++;
                if(right - unbalanced_right > left)
                    unbalanced_right ++;
            }
        }
    
        if(left > (right - unbalanced_right)) 
            unbalanced_left = left - (right - unbalanced_right);
        
        vector<string> ans;
        dfs(s, unbalanced_left, unbalanced_right, ans, 0);

        //if(ans.size() == 0) ans.push_back("");
        return ans;
    }

private:
    void dfs(string &s, int left, int right, vector<string> &ans, int pos){
        if(left == 0 && right == 0){

            int unbalanced_left = 0, unbalanced_right = 0;
            int left_num = 0, right_num = 0;
            for(auto &c : s){
                if(c == '(') left_num ++;

                if(c == ')') {
                    right_num ++;
                    if(right_num - unbalanced_right > left_num)
                        unbalanced_right ++;
                }
            }
        
            if(left_num > (right_num - unbalanced_right)) 
                unbalanced_left = left_num - (right_num - unbalanced_right);

            if(unbalanced_right == 0 && unbalanced_left == 0)
                ans.push_back(s);

            return;
        }

        char symbol = (right == 0) ? '(' : ')';

        for(int i = pos; i < s.size(); i ++){
            if(s[i] == symbol && i == 0 || (s[i] == symbol && s[i-1] != symbol)){
                //cout << "delete :" << s[i] << " " << s[i-1] << endl;
                
                string::iterator it = s.begin();
                s.erase(it + i);    
                //cout << s << endl;

                if(symbol == '('){
                    dfs(s, left - 1, right, ans, i);
                    //cout << "before recover : " << s << endl;
                    s.insert(it + i, '(');
                    //cout << "recover : " << s << endl;
                }else{
                    dfs(s, left, right - 1, ans, i);
                    // cout << "before recover : " << s << endl;
                    s.insert(it + i, ')');
                    //cout << "recover : " << s << endl;
                }
                
            }
        }
    }
};

int main(){

    Solution sol;

    for(auto &res : sol.removeInvalidParentheses(")))))())))))())))))))(()(((((((")){
        cout << res << endl;
    }

    return 0;
}