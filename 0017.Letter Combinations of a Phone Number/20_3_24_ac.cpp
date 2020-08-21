# include <iostream>
# include <string>
# include <vector>

using namespace std;

/**
 *  runtime 4ms 40.60% 
 **/
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> keyboard = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};    
        vector<string> res;

        if(digits == "") return res;

        string cur;
        dfs(digits, keyboard, 1, cur, res);

        return res;
    }

private:
    void dfs(string digits, vector<string> keyboard, int layer, string &cur, vector<string> &res){
        if(layer > digits.length()){
            res.push_back(cur);
            return;
        }

        int digit = digits[layer - 1] - '0';
        string letters = keyboard[digit];
        for(int i = 0; i < letters.length(); i ++){
            cur += letters[i];
            
            dfs(digits, keyboard, layer+1, cur, res);

            cur.pop_back();
        }
    }
};

int main(){
    Solution sol;

    vector<string> res = sol.letterCombinations("");
    for(vector<string>::iterator it = res.begin(); it != res.end(); it ++){
        cout << *it << endl;
    }
}