# include <iostream>
# include <string>
# include <vector>

using namespace std;

// time complexity : O(4^n), 100% 
// memory complexity : O(4^n + n)
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> keyboard = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};    
        vector<string> res;

        if(digits == "") return res;

        string cur;
        dfs(digits, keyboard, 0, cur, res);

        return res;
    }

private:
    void dfs(string digits, vector<string> keyboard, int layer, string &cur, vector<string> &res){
        if(layer >= digits.size()){
            res.push_back(cur);
            return;
        }

        for(int i = 0; i < keyboard[digits[layer] - '0'].size(); i ++){
            //cout << keyboard[digits[layer] - '0'] << endl;
            cur += keyboard[digits[layer] - '0'][i];
            dfs(digits, keyboard, layer + 1, cur, res);
            cur.pop_back();
        }
    }
};

int main(){
    Solution sol;

    vector<string> res = sol.letterCombinations("23");
    for(vector<string>::iterator it = res.begin(); it != res.end(); it ++){
        cout << *it << endl;
    }
}