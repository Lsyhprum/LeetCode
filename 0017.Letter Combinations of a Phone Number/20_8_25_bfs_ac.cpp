# include <iostream>
# include <string>
# include <vector>

using namespace std;

// time complexity : O(4^n), 100% 
// memory complexity : O(2*4^n)
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};

        vector<string> keyboard = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};    
        vector<string> res {""};

        for(char digit : digits) {
            vector<string> tmp;
            for(const string& s : res)
                for(char c : keyboard[digit - '0'])
                    tmp.push_back(s + c);

            res.swap(tmp);
        }

        return res;
    }
};

int main(){
    Solution sol;

    vector<string> res = sol.letterCombinations("23");
    for(vector<string>::iterator it = res.begin(); it != res.end(); it ++){
        cout << *it << endl;
    }
}