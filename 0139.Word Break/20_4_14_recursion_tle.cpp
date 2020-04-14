# include <iostream>
# include <vector>

using namespace std;

// TLE：查找 wordDict 费时，最差 n^2
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        if(s.empty()) return true;         // non-empty string s

        for(string word : wordDict){
            int len = word.length();
            if(s.substr(0, len) == word){
                if(wordBreak(s.substr(len, s.length()), wordDict))
                    return true;
            }
        }

        return false;
    }
};

int main(){
    Solution sol;
    vector<string> wordDict = {"cats", "dog", "sand", "and", "cat"};
    cout << sol.wordBreak("catsandog", wordDict);
    return 0;
}