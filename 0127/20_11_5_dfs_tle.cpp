#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        wordList.insert(wordList.begin(), beginWord);
        std::vector<std::vector<int>> trans(wordList.size(), std::vector<int>(wordList.size(), beginWord.size()));
        std::vector<bool> flags(wordList.size(), false);

        for(int i = 0; i < wordList.size(); i ++) {
            for(int j = i; j < wordList.size(); j ++) {
                trans[i][j] = diff(wordList[i], wordList[j]);
                trans[j][i] = trans[i][j];
            }
        }

        int level = wordList.size() + 1;
        int cur = 1;
        flags[0] = true;
        dfs(trans, wordList, flags, endWord, 0, cur, level);

        // for(int i = 0; i < wordList.size(); i ++) {
        //     for(int j = 0; j < wordList.size(); j ++) {
        //         std::cout << trans[i][j] << " ";
        //     }
        //     std::cout << std::endl;
        // }

        return (level == wordList.size() + 1) ? 0 : level;
    }

private:

    int diff(string s1, string s2) {
        int num = 0;
        for(int i = 0; i < s1.size(); i ++) {
            if(s1[i] != s2[i]) num ++;
        }
        return num;
    }

    void dfs(const std::vector<std::vector<int>> trans, const vector<string> list, std::vector<bool> &flags, const string endWord, int pos, int &cur, int &level) {
        if(list[pos] == endWord) {
            if(level > cur) level = cur;
            return;
        }

        // std::cout << list[pos] << std::endl;
        // for(int i = 0; i < flags.size(); i ++)
        //     std::cout << flags[i] << " ";
        // std::cout << std::endl;

        for(int i = 1; i < trans.size(); i ++) {
            if(flags[i] == false && trans[pos][i] == 1) {
                cur += 1;
                flags[i] = true;
                dfs(trans, list, flags, endWord, i, cur, level);
                flags[i] = false;
                cur -= 1;
            }
        }
    }
};

int main() {
    Solution sol;
    vector<string> v = {"hot","dot","dog","lot","log"};
    std::cout << sol.ladderLength("hit", "cog", v);
    return 0;
}