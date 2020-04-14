# include <iostream>
# include <unordered_set>
# include <vector>

using namespace std;

// 将 n * n -> n
// Runtime 25.26%
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        vector<int> memo(s.length(), -1);

        return dp(s, wordSet, 0, memo);
    }

    bool dp(string s, unordered_set<string>& wordSet, int start, vector<int> &memo){
        if(start >= s.length()) return true;
        if(memo[start] != -1) return memo[start];

        for(int i = start + 1; i <= s.length(); i ++){
            if(wordSet.count(s.substr(start, i - start)) && dp(s, wordSet, i, memo)){
                return memo[start] = 1;
            }
        }
       
        return memo[start] = 0;
    }
};

int main(){
    Solution sol;
    
    vector<string> wordDict = {"a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"};
    cout << sol.wordBreak("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab", wordDict);
    return 0;
}